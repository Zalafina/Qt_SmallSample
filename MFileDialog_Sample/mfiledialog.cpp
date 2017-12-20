#include <QListView>
#include <QTreeView>
#include <QDialogButtonBox>
#include <QDebug>
#include "mfiledialog.h"

MFileDialog::MFileDialog(QWidget *parent) :
    QFileDialog(parent)
{
    this->setOption(QFileDialog::DontUseNativeDialog,true);

    // Support multiple choice
    QListView *pListView = this->findChild<QListView*>("listView");
    if (pListView){
        pListView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    }
    QTreeView *pTreeView = this->findChild<QTreeView*>();
    if (pTreeView){
        pTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    }
    QDialogButtonBox *pButton = this->findChild<QDialogButtonBox *>("buttonBox");

    // Change accepted signal to trigger custom slot.
    disconnect(pButton, SIGNAL(accepted()), this, SLOT(accept()));
    connect(pButton, SIGNAL(accepted()), this, SLOT(onChiose()));
}

MFileDialog::~MFileDialog()
{

}

void MFileDialog::onChiose()
{
    QDialog::accept();
}
