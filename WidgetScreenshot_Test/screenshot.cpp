#include "screenshot.h"
#include "ui_screenshot.h"

Screenshot::Screenshot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screenshot)
{
    ui->setupUi(this);
}

Screenshot::~Screenshot()
{
    delete ui;
}

void Screenshot::on_pushButton_clicked()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap mainscreen = screen->grabWindow(0);

    bool saveresult;
    saveresult = mainscreen.save(QString("screen_shot.png"), "PNG");
    qDebug() << "saveresult:" << saveresult;
}
