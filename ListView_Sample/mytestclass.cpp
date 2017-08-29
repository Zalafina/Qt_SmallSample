#include <QThread>
#include <QSettings>
#include "mytestclass.h"
#include "dataobject.h"

MyTestClass::MyTestClass(QObject *parent) : QObject(parent)
  , m_firstcolor()
  , m_secondcolor()
{
    static_cast<void>(QObject::connect(this, SIGNAL(iconClicked(quint32, QString)), this, SLOT(iconClickedInfo(quint32, QString)), Qt::AutoConnection));

    m_firstcolor    << "red"
                    << "green"
                    << "blue"
                    << "yellow";

    m_secondcolor   << "orange"
                    << "purple"
                    << "cyan"
                    << "magenta";

    m_dataList.append(new DataObject("Item 1", m_firstcolor[0], m_secondcolor[0]));
    m_dataList.append(new DataObject("Item 2", m_firstcolor[1], m_secondcolor[1]));
    m_dataList.append(new DataObject("Item 3", m_firstcolor[2], m_secondcolor[2]));
    m_dataList.append(new DataObject("Item 4", m_firstcolor[3], m_secondcolor[3]));
}

void MyTestClass::clickInterfaceForQML(quint32 clickIndex, QString itemName)
{
    qDebug("clickInterfaceForQML:: Index(%d), itemName(%s)", clickIndex, itemName.toLatin1().constData());
    emit iconClicked(clickIndex, itemName);
}

void MyTestClass::iconClickedInfo(quint32 clickIndex, QString itemName)
{
    qDebug("iconClickedInfo:: Index(%d), itemName(%s)", clickIndex, itemName.toLatin1().constData());

    for(const auto data : m_dataList) {
        DataObject *tempdata = dynamic_cast<DataObject*>(data);
        if (tempdata->name() == itemName){
            QString tempstring = tempdata->color();
            tempdata->setColor(tempdata->m_color_backup);
            tempdata->m_color_backup = tempstring;
            qDebug("%s setColor(%s)", tempdata->m_name.toLatin1().constData(), tempdata->m_color.toLatin1().constData());
        }
    }
}

