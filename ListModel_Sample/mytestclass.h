#ifndef MYTESTCLASS_H
#define MYTESTCLASS_H

#include <QDebug>
#include <QObject>
#include <QHash>
#include <QVariant>
#include <QQuickView>
#include <QQuickItem>

class MyTestClass : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> dataList READ get_datalist WRITE set_datalist NOTIFY datalist_Changed)

public:
    explicit MyTestClass(QQuickView * viewer, QObject *parent = 0);

    Q_INVOKABLE void clickInterfaceForQML(quint32 clickIndex);
    Q_INVOKABLE void iconDragAndDrop(quint32 sourceIndex, quint32 destIndex);

    QList<QObject*> get_datalist() const;
    void set_datalist(const QList<QObject*> &datalist);

signals:
    void datalist_Changed();

    void iconClicked(quint32 clickIndex);
    void listmodelChanged(quint32 clickIndex);

public slots:
    void iconClickedInfo(quint32 clickIndex);

private:
    void init_AppModelNameMap(void);

    QHash<quint32, const char *> m_AppModel_NameMap;
    QString class_string;
    QByteArray class_bytearray;
    QVariant class_variant;

public:
    QQuickView * m_Viewer;
    QList<QObject*> m_dataList;
};

#endif // MYTESTCLASS_H
