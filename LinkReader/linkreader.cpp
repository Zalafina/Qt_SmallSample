#include "linkreader.h"
#include "ui_linkreader.h"

// ResolveIt - Uses the Shell's IShellLink and IPersistFile interfaces
//             to retrieve the path and description from an existing shortcut.
//
// Returns the result of calling the member functions of the interfaces.
//
// Parameters:
// hwnd         - A handle to the parent window. The Shell uses this window to
//                display a dialog box if it needs to prompt the user for more
//                information while resolving the link.
// lpszLinkFile - Address of a buffer that contains the path of the link,
//                including the file name.
// lpszPath     - Address of a buffer that receives the path of the link
//                target, including the file name.
// lpszDesc     - Address of a buffer that receives the description of the
//                Shell link, stored in the Comment field of the link
//                properties.

HRESULT ResolveIt(HWND hwnd, LPCSTR lpszLinkFile, LPWSTR lpszPath, int iPathBufferSize, LPWSTR lpszDesc);

HRESULT ResolveIt(HWND hwnd, LPCSTR lpszLinkFile, LPWSTR lpszPath, int iPathBufferSize, LPWSTR lpszDesc)
{
    HRESULT hres;
    IShellLink* psl;
    WCHAR szGotPath[MAX_PATH];
    WCHAR szDescription[MAX_PATH];
    WIN32_FIND_DATA wfd;

    *lpszPath = 0; // Assume failure

    // Get a pointer to the IShellLink interface. It is assumed that CoInitialize
    // has already been called.
    hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl);
    if (SUCCEEDED(hres))
    {
        IPersistFile* ppf;

        // Get a pointer to the IPersistFile interface.
        hres = psl->QueryInterface(IID_IPersistFile, (void**)&ppf);

        if (SUCCEEDED(hres))
        {
            WCHAR wsz[MAX_PATH];

            // Ensure that the string is Unicode.
            MultiByteToWideChar(CP_ACP, 0, lpszLinkFile, -1, wsz, MAX_PATH);

            // Add code here to check return value from MultiByteWideChar
            // for success.

            // Load the shortcut.
            hres = ppf->Load(wsz, STGM_READ);

            if (SUCCEEDED(hres))
            {
                // Resolve the link.
                hres = psl->Resolve(hwnd, 0);

                if (SUCCEEDED(hres))
                {
                    // Get the path to the link target.
                    //hres = psl->GetPath(szGotPath, MAX_PATH, (WIN32_FIND_DATA*)&wfd, SLGP_SHORTPATH); /* "SLGP_SHORTPATH" is for retrieve dos format 8.3 file path */
                    hres = psl->GetPath(szGotPath, MAX_PATH, (WIN32_FIND_DATA*)&wfd, SLGP_RAWPATH);

                    if (SUCCEEDED(hres))
                    {
                        // Get the description of the target.
                        hres = psl->GetDescription(szDescription, MAX_PATH);

                        if (SUCCEEDED(hres))
                        {
                            hres = StringCbCopy(lpszPath, iPathBufferSize, szGotPath);
                            if (SUCCEEDED(hres))
                            {
                                // Handle success
                                hres = StringCbCopy(lpszDesc, iPathBufferSize, szDescription);
                            }
                            else
                            {
                                // Handle the error
                            }
                        }
                    }
                }
            }

            // Release the pointer to the IPersistFile interface.
            ppf->Release();
        }

        // Release the pointer to the IShellLink interface.
        psl->Release();
    }
    return hres;
}

LinkReader::LinkReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinkReader)
{
    ui->setupUi(this);
}

LinkReader::~LinkReader()
{
    delete ui;
}

void LinkReader::on_readlinkButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Link File",
                                                    NULL,
                                                    "Link Files (*.lnk)");

    if (fileName.length() != 0){
        qDebug() << fileName;

        TCHAR szTargetPath[MAX_PATH] = TEXT("");
        TCHAR szTargetDesc[MAX_PATH] = TEXT("");
        HRESULT hres;
        hres = ResolveIt(NULL, fileName.toStdString().c_str(), szTargetPath, MAX_PATH, szTargetDesc);

        if (SUCCEEDED(hres)){
            qDebug() << "ResolveIt Succeeded";

            QString targetPathStr = QString::fromWCharArray(szTargetPath);
            QString targetDescStr = QString::fromWCharArray(szTargetDesc);

            if (targetPathStr.length() > 0){
                ui->lineEdit->setText(targetPathStr);
            }

            qDebug() << "Target Path:" << targetPathStr;
            qDebug() << "Target Description:" << targetDescStr;
        }
        else{
            qDebug() << "ResolveIt Failed!!!";
        }
    }
    else{
    }

}
