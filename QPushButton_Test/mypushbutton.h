#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

protected:
    void changeEvent(QEvent *event);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
