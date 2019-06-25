#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QWidget>
#include <QDebug>
#include <QScreen>

namespace Ui {
class Screenshot;
}

class Screenshot : public QWidget
{
    Q_OBJECT

public:
    explicit Screenshot(QWidget *parent = 0);
    ~Screenshot();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Screenshot *ui;
};

#endif // SCREENSHOT_H
