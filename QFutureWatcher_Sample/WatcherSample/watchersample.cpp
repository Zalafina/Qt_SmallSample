#include "watchersample.h"
#include "ui_watchersample.h"

WatcherSample::WatcherSample(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WatcherSample),
    m_param_value(2)
{
    ui->setupUi(this);
}

WatcherSample::~WatcherSample()
{
    delete ui;
}

int g_param_value = 2;

int WatcherSample::compute_func(int count_value)
{
    qDebug() << __FUNCTION__ << "count_value start :" << count_value;
    count_value = count_value * 2;
    qDebug() << __FUNCTION__ << "count_value end   :" << count_value;

    return count_value;
}

int compute(int count_value)
{
    qDebug() << __FUNCTION__ << "count_value start :" << count_value;
    count_value = count_value * 2;
    qDebug() << __FUNCTION__ << "count_value end   :" << count_value;

    return count_value;
}

void WatcherSample::on_watcherButton_clicked()
{
    QtConcurrent::run(this, &WatcherSample::compute_func, m_param_value);
}

void WatcherSample::on_pushButton_clicked()
{
    qDebug() << m_param_value;
}
