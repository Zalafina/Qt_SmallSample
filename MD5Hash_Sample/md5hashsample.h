#ifndef MD5HASHSAMPLE_H
#define MD5HASHSAMPLE_H

#include <QDialog>
#include <QDebug>
#include <QCryptographicHash>
#include <QSettings>

namespace Ui {
class MD5HashSample;
}

class MD5HashSample : public QDialog
{
    Q_OBJECT

public:
    explicit MD5HashSample(QWidget *parent = 0);
    ~MD5HashSample();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MD5HashSample *ui;
};

#endif // MD5HASHSAMPLE_H
