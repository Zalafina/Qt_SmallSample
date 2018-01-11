#ifndef WATCHERSAMPLE_H
#define WATCHERSAMPLE_H

#include <QDialog>
#include <QDebug>
#include <QtConcurrent>

namespace Ui {
class WatcherSample;
}

class WatcherSample : public QDialog
{
    Q_OBJECT

public:
    explicit WatcherSample(QWidget *parent = 0);
    ~WatcherSample();

    int compute_func(int count_value);

private slots:
    void on_watcherButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::WatcherSample *ui;

public:
    int m_param_value;
};

#endif // WATCHERSAMPLE_H
