#ifndef QVARIANT_KEY_H
#define QVARIANT_KEY_H

#include <QWidget>

uint qHash(const QVariant & var);

namespace Ui {
class QVariant_Key;
}

class QVariant_Key : public QWidget
{
    Q_OBJECT

public:
    explicit QVariant_Key(QWidget *parent = 0);
    ~QVariant_Key();

private:
    Ui::QVariant_Key *ui;
};

#endif // QVARIANT_KEY_H
