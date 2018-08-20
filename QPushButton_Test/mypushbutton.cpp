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

        QString tempString = this->objectName();
        if (this->objectName() == QString("pushButtonA")){
            emit enableStatusChanged(this->isEnabled(), 1);
        }
        else if (this->objectName() == QString("pushButtonB")){
            emit enableStatusChanged(this->isEnabled(), 2);
        }
        else if (this->objectName() == QString("pushButtonC")){
            emit enableStatusChanged(this->isEnabled(), 3);
        }
    }
    QPushButton::changeEvent(event);
}
