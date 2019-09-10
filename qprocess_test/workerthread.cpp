#include "workerthread.h"

static const qint64 READ_LEN_MAX  = 8192;

workerThread::workerThread(QObject *parent) : QObject(parent),
    m_CMD_PID(-1)
{

}

workerThread::~workerThread()
{
    consoleProcess->close();

    delete consoleProcess;

    consoleProcess = Q_NULLPTR;
    qDebug() << "consoleProcess End";

}

void workerThread::readSlot()
{
    while(consoleProcess->canReadLine())
    {
        char console_output[READ_LEN_MAX+1];
        qint64 readlineLength = consoleProcess->readLine(console_output, READ_LEN_MAX);
        if (readlineLength != -1) {
            QString tmpstr = QString::fromLocal8Bit(console_output);
            emit senddata_sign(tmpstr);
        }
    }
}

void workerThread::writeSlot(QString strWrite)
{
    //qDebug() << "WriteCMD:" << strWrite.toStdString().c_str();
    QByteArray writeBArray = strWrite.toStdString().c_str();
    consoleProcess->write(writeBArray.constData());
    consoleProcess->waitForBytesWritten(2000);
}

void workerThread::IniConsoleThreadSlot()
{
    consoleProcess = new QProcess(this);
    consoleProcess->setProcessChannelMode(QProcess::MergedChannels);

    QObject::connect(consoleProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readSlot()));

//    QString program("java.exe");
    QString program("E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/vts-tradefed_win.bat");

//    QString nativearg("-cp \"E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../../android-vts/tools/tradefed.jar;E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../../android-vts/tools/loganalysis.jar;E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../../android-vts/tools/hosttestlib.jar;E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../../android-vts/tools/vts-tradefed.jar;E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../../android-vts/tools/vts-tradefed-tests.jar;E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../../android-vts/tools/compatibility-host-util.jar;E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../../android-vts/testcases/*\" \"-DVTS_ROOT=E:/work/gsda2.0/vts/vts_root_newd/android-vts/tools/../..\" com.android.compatibility.common.tradefed.command.CompatibilityConsole");

//    QString workingdir("E:\\work\\gsda2.0\\vts\\vts_root_newd\\android-vts\\tools\\..\\..\\android-vts\\testcases");
//    consoleProcess->setWorkingDirectory(workingdir);

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    if (true == env.contains("PATH")){
        QString path = env.value("PATH");
        path = path.prepend("E:\\work\\gsda2.0\\vts\\vts_root_newd\\vts_bin;");
        env.insert("PATH", path);
    }
    consoleProcess->setProcessEnvironment(env);

    consoleProcess->setProgram(program);
//    consoleProcess->setNativeArguments(nativearg);


#if 1
    qint64 pid = 0;
    bool startresult = false;
    startresult = consoleProcess->startDetached(&pid);
    if (true == startresult){
        m_CMD_PID = pid;
        qDebug("ConsoleProcess startDetached PID(%ld)", pid);
    }
#else

    consoleProcess->start();
    if (!consoleProcess->waitForStarted())
        qDebug() << "Started failed:" << consoleProcess->errorString();
    else
    {
        qDebug() << "Console Process Started:";
        qDebug() << consoleProcess->readAll();
    }
#endif
}

void workerThread::attachConsoleSlot(quint64 pid)
{

    if (m_CMD_PID != -1){
        DWORD processID = static_cast<DWORD>(pid);
        HWND hWnd = getHWND_byPID(processID);

#if 0
        QByteArray temp_string("test\n");
        for(const char byte : temp_string){
            SendMessage(hWnd, WM_CHAR, byte, 0);
        }
#endif
        QTimer::singleShot(2000, this, [=](){
            qDebug() << "Timeout 2000";

            PostMessage(hWnd, WM_KEYDOWN, VK_SPACE, 0);
            QThread::msleep(100);
            PostMessage(hWnd, WM_KEYUP, VK_SPACE, 0);
            QThread::msleep(100);
        });

        QTimer::singleShot(3000, this, [=](){
            qDebug() << "Timeout 3000";

            PostMessage(hWnd, WM_KEYDOWN, VK_SPACE, 0);
            QThread::msleep(100);
            PostMessage(hWnd, WM_KEYUP, VK_SPACE, 0);
            QThread::msleep(100);
        });

        QTimer::singleShot(4000, this, [=](){
            qDebug() << "Timeout 4000";

            PostMessage(hWnd, WM_KEYDOWN, VK_SPACE, 0);
            QThread::msleep(100);
            PostMessage(hWnd, WM_KEYUP, VK_SPACE, 0);
            QThread::msleep(100);
        });

        QTimer::singleShot(5000, this, [=](){
            qDebug() << "Timeout 5000";

            PostMessage(hWnd, WM_KEYDOWN, VK_SPACE, 0);
            QThread::msleep(100);
            PostMessage(hWnd, WM_KEYUP, VK_SPACE, 0);
            QThread::msleep(100);
        });


#if 0
        PostMessage(hWnd, WM_KEYDOWN, VK_L, 0);
        QThread::msleep(100);
        PostMessage(hWnd, WM_KEYUP, VK_L, 0);
        QThread::msleep(100);

        PostMessage(hWnd, WM_KEYDOWN, VK_SPACE, 0);
        QThread::msleep(100);
        PostMessage(hWnd, WM_KEYUP, VK_SPACE, 0);
        QThread::msleep(100);

        PostMessage(hWnd, WM_KEYDOWN, VK_M, 0);
        QThread::msleep(100);
        PostMessage(hWnd, WM_KEYUP, VK_M, 0);
        QThread::msleep(100);

        PostMessage(hWnd, WM_KEYDOWN, VK_RETURN, 0);
        QThread::msleep(100);
        PostMessage(hWnd, WM_KEYUP, VK_RETURN, 0);
        QThread::msleep(100);
#endif


#if 0
        // Get a handle to the process.
        HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                       PROCESS_VM_OPERATION |
                                       PROCESS_VM_WRITE |
                                       PROCESS_VM_READ,
                                       FALSE, processID );

        if (Q_NULLPTR != hProcess )
        {
            CloseHandle( hProcess );
        }
#endif
    }
}

HWND workerThread::getHWND_byPID(DWORD dwProcessID)
{
    HWND hWnd = GetTopWindow(Q_NULLPTR);
    while ( hWnd )
    {
        DWORD pid = 0;
        DWORD dwTheardId = GetWindowThreadProcessId( hWnd,&pid);
        if (dwTheardId != 0)
        {
            if ( pid == dwProcessID/*your process id*/ )
            {
                // here h is the handle to the window

                if (GetTopWindow(hWnd))
                {
                    return hWnd;
                }
               // return h;
            }
        }
        hWnd = ::GetNextWindow( hWnd , GW_HWNDNEXT);
    }
    return Q_NULLPTR;
}
