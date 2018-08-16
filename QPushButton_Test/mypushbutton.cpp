#include <QDebug>
#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

void MyPushButton::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::EnabledChange)
    {
        qDebug() << this->objectName() << ": EnabledChange to" << this->isEnabled();
    }
    QPushButton::changeEvent(event);
}
