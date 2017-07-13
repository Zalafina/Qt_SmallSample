#ifndef MYTESTCLASS_H
#define MYTESTCLASS_H

#include <QObject>
#include <QHash>
#include <QVariant>
#include <QFile>
#include <QtCore/QMetaEnum>

class MyTestClass : public QObject
{
    Q_OBJECT
public:
    explicit MyTestClass(QObject *parent = 0);    

    enum Test_Enum
    {
        ENUM_A = 101,
        ENUM_B = 202,
        ENUM_C = 303,
        ENUM_D = 404,
        ENUM_E = 505
    };
    Q_ENUM(Test_Enum)

    Q_INVOKABLE void loadConfigFileInterfaceForQML(void);
signals:
    void signalForLoadConfigFile(void);

public slots:
    void loadConfigFile(void);
    void threadStarted(void);

private:
    void req_ReGenerateVehicleID(void);
    void init_AppModelNameMap(void);

    QHash<quint32, const char *> m_AppModel_NameMap;
    QString class_string;
    QByteArray class_bytearray;
    QVariant class_variant;
};

#endif // MYTESTCLASS_H
