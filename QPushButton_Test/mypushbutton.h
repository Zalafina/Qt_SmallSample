#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QDebug>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

protected:
    void changeEvent(QEvent *event);

signals:
    void enableStatusChanged(bool status, quint32 buttonindex);

public slots:
};

#endif // MYPUSHBUTTON_H
