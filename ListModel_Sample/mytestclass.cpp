#include <QThread>
#include <QSettings>
#include "mytestclass.h"
#include "dataobject.h"

MyTestClass::MyTestClass(QQuickView *viewer, QObject *parent) :
    QObject(parent)
  , m_Viewer(viewer)
  , m_AppModel_NameMap()
{
    static_cast<void>(QObject::connect(this, SIGNAL(iconClicked(quint32)), this, SLOT(iconClickedInfo(quint32)), Qt::AutoConnection));

    m_dataList.append(new DataObject("ICON_01", "pics/AudioPlayer_48.png"));
    m_dataList.append(new DataObject("ICON_02", "pics/VideoPlayer_48.png"));
    m_dataList.append(new DataObject("ICON_03", "pics/Camera_48.png"));
    m_dataList.append(new DataObject("ICON_04", "pics/DateBook_48.png"));
    m_dataList.append(new DataObject("ICON_05", "pics/EMail_48.png"));
    m_dataList.append(new DataObject("ICON_06", "pics/TodoList_48.png"));
    m_dataList.append(new DataObject("ICON_07", "pics/AddressBook_48.png"));
}

void MyTestClass::clickInterfaceForQML(quint32 clickIndex)
{
    qDebug("Called clickInterfaceForQML(%d)", clickIndex);
    emit iconClicked(clickIndex);
}

void MyTestClass::iconDragAndDrop(quint32 sourceIndex, quint32 destIndex)
{
    qDebug() << "sourceIndex:" << sourceIndex << "destIndex:" << destIndex;
}

QList<QObject *> MyTestClass::get_datalist() const
{
    return m_dataList;
}

void MyTestClass::set_datalist(const QList<QObject *> &datalist)
{
    m_dataList = datalist;

    qDebug() << "set_datalist Called";
    foreach(QObject * const data, m_dataList) {
        DataObject *tempdata = dynamic_cast<DataObject*>(data);
        qDebug("data name:%s", tempdata->m_name.toLatin1().constData());
        qDebug("data icon:%s", tempdata->m_icon.toLatin1().constData());
    }
}

void MyTestClass::iconClickedInfo(quint32 clickIndex)
{
    qDebug("iconClickedInfo(%d) Called", clickIndex);

    foreach(QObject * const data, m_dataList) {
        DataObject *tempdata = dynamic_cast<DataObject*>(data);
        qDebug("data name:%s", tempdata->m_name.toLatin1().constData());
        qDebug("data icon:%s", tempdata->m_icon.toLatin1().constData());
    }
}

