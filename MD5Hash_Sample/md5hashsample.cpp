#include "md5hashsample.h"
#include "ui_md5hashsample.h"

MD5HashSample::MD5HashSample(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MD5HashSample)
{
    ui->setupUi(this);
}

MD5HashSample::~MD5HashSample()
{
    delete ui;
}

void MD5HashSample::on_pushButton_clicked()
{
    QString test_string("a test string for MD5 hash");

    QByteArray md5_hash;
    md5_hash = QCryptographicHash::hash(test_string.toUtf8(), QCryptographicHash::Md5);
    QString md5hash_string = md5_hash.toHex();

    qDebug() << "MD5-Hash:" << md5hash_string;

    // write to md5_hash.ini
    QSettings md5writeFile(QString("config//md5_hash.ini"), QSettings::IniFormat);
    md5writeFile.setValue(QLatin1String("MD5-Hash"), md5_hash);
    md5writeFile.sync();

    // read from  md5_hash.ini
    QSettings md5readFile(QString("config//md5_hash.ini"), QSettings::IniFormat);
    md5readFile.sync();

    if (true == md5readFile.contains("MD5-Hash")){
        QByteArray md5_array = md5readFile.value("MD5-Hash").toByteArray();

        qDebug() << "MD5-Hash read from file:" << md5_array.toHex();
    }
}
