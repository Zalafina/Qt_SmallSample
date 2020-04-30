#include "qvariant_key.h"
#include "ui_qvariant_key.h"

#include <QSet>
#include <QVariant>

uint qHash(const QVariant & var)
{
    if ( !var.isValid() || var.isNull() )
        //return -1;
        Q_ASSERT(0);

    switch ( var.type() )
    {
        case QVariant::Int:
                return qHash( var.toInt() );
            break;
        case QVariant::UInt:
                return qHash( var.toUInt() );
            break;
        case QVariant::Bool:
                return qHash( var.toUInt() );
            break;
        case QVariant::Double:
                return qHash( var.toUInt() );
            break;
        case QVariant::LongLong:
                return qHash( var.toLongLong() );
            break;
        case QVariant::ULongLong:
                return qHash( var.toULongLong() );
            break;
        case QVariant::String:
                return qHash( var.toString() );
            break;
        case QVariant::Char:
                return qHash( var.toChar() );
            break;
        case QVariant::StringList:
                return qHash( var.toString() );
            break;
        case QVariant::ByteArray:
                return qHash( var.toByteArray() );
            break;
        case QVariant::Date:
        case QVariant::Time:
        case QVariant::DateTime:
        case QVariant::Url:
        case QVariant::Locale:
        case QVariant::RegExp:
                return qHash( var.toString() );
            break;
        case QVariant::Map:
        case QVariant::List:
        case QVariant::BitArray:
        case QVariant::Size:
        case QVariant::SizeF:
        case QVariant::Rect:
        case QVariant::LineF:
        case QVariant::Line:
        case QVariant::RectF:
        case QVariant::Point:
        case QVariant::PointF:
            // not supported yet
            break;
        case QVariant::UserType:
        case QVariant::Invalid:
        default:
            return -1;
    }

    // could not generate a hash for the given variant
    return -1;
}

QVariant_Key::QVariant_Key(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QVariant_Key)
{
    ui->setupUi(this);

    QSet<QVariant> ss;
    ss.insert(QString("ss"));
}

QVariant_Key::~QVariant_Key()
{
    delete ui;
}
