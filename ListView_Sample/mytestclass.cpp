#include <QThread>
#include <QSettings>
#include "mytestclass.h"
#include "dataobject.h"

MyTestClass::MyTestClass(QObject *parent) : QObject(parent)
  , m_firstcolor()
  , m_secondcolor()
{
    static_cast<void>(QObject::connect(this, SIGNAL(iconClicked(quint32)), this, SLOT(iconClickedInfo(quint32)), Qt::AutoConnection));

    m_firstcolor    << "red"
                    << "green"
                    << "blue"
                    << "yellow";

    m_secondcolor   << "orange"
                    << "purple"
                    << "cyan"
                    << "magenta";

    m_dataList.append(new DataObject("Item 1", m_firstcolor[0]));
    m_dataList.append(new DataObject("Item 2", m_firstcolor[1]));
    m_dataList.append(new DataObject("Item 3", m_firstcolor[2]));
    m_dataList.append(new DataObject("Item 4", m_firstcolor[3]));
}

void MyTestClass::clickInterfaceForQML(quint32 clickIndex)
{
    qDebug("Called clickInterfaceForQML(%d)", clickIndex);
    emit iconClicked(clickIndex);
}

void MyTestClass::iconClickedInfo(quint32 clickIndex)
{
    static bool itemclickflags[4] = {false};

    qDebug("iconClickedInfo(%d) Called", clickIndex);

    if (clickIndex < 4){
        if (false == itemclickflags[clickIndex]){
            dynamic_cast<DataObject*>(m_dataList[clickIndex])->setColor(m_secondcolor[clickIndex]);
            itemclickflags[clickIndex] = true;
        }
        else{
            dynamic_cast<DataObject*>(m_dataList[clickIndex])->setColor(m_firstcolor[clickIndex]);
            itemclickflags[clickIndex] = false;
        }
    }
    else{
        qDebug("iconClickedIndexError!!!");
        return;
    }

    for(QObject * const data : m_dataList) {
        DataObject *tempdata = dynamic_cast<DataObject*>(data);
        qDebug("data name:%s", tempdata->m_name.toLatin1().constData());
        qDebug("data color:%s", tempdata->m_color.toLatin1().constData());
    }
}

