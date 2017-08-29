#ifndef MYTESTCLASS_H
#define MYTESTCLASS_H

#include <QObject>
#include <QHash>
#include <QVariant>

class MyTestClass : public QObject
{
    Q_OBJECT
public:
    explicit MyTestClass(QObject *parent = 0);    

    Q_INVOKABLE void clickInterfaceForQML(quint32 clickIndex);
signals:
    void iconClicked(quint32 clickIndex);
    void listmodelChanged(quint32 clickIndex);

public slots:
    void iconClickedInfo(quint32 clickIndex);

private:
    void init_AppModelNameMap(void);

    QString class_string;
    QByteArray class_bytearray;
    QVariant class_variant;

public:
    QList<QObject*> m_dataList;
    QStringList m_firstcolor;
    QStringList m_secondcolor;
};

#endif // MYTESTCLASS_H
