#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_a_clicked();

    void on_pushButton_b_clicked();

    void on_pushButton_c_clicked();

    void check_focus(void);

    void hide_timeOut(void);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
