#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_a->setFocusPolicy(Qt::TabFocus);
    ui->pushButton_b->setFocusPolicy(Qt::TabFocus);
    ui->pushButton_c->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_a->setAutoDefault(true);
    ui->pushButton_b->setAutoDefault(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_a_clicked()
{

}

void MainWindow::on_pushButton_b_clicked()
{

}

void MainWindow::on_pushButton_c_clicked()
{
    qDebug() << "ui->pushButton_a->hasFocus() : " << ui->pushButton_a->hasFocus();
    qDebug() << "ui->pushButton_b->hasFocus() : " << ui->pushButton_b->hasFocus();

    hide();

    QTimer::singleShot(3000, Qt::PreciseTimer, this, SLOT(hide_timeOut()));
}

void MainWindow::check_focus()
{
    qDebug() << "ui->pushButton_a->hasFocus()@check_focus() : " << ui->pushButton_a->hasFocus();
    qDebug() << "ui->pushButton_b->hasFocus()@check_focus() : " << ui->pushButton_b->hasFocus();
}

void MainWindow::hide_timeOut(void)
{
    qDebug() << "hide_timeOut() called";
    showNormal();
    activateWindow();
    raise();
    QApplication::setActiveWindow(this);

//    __asm {
//        nop;
//        nop;
//        nop;
//        nop;
//    };

    __asm(
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop"
    );

    qDebug() << "ui->pushButton_a->hasFocus() : " << ui->pushButton_a->hasFocus();
    qDebug() << "ui->pushButton_b->hasFocus() : " << ui->pushButton_b->hasFocus();

    QTimer::singleShot(1000, Qt::PreciseTimer, this, SLOT(check_focus()));
}
