#ifndef FPMAP_H
#define FPMAP_H

#include <QObject>

typedef struct stHMIEvent {
    quint32     eventId;
    quint32     param;
    quint32     param_Ex[4];
} HMI_EVENT;

class FPMap : public QObject
{
    Q_OBJECT
public:
    explicit FPMap(QObject *parent = 0);

    enum ProcResult
    {
        RESULT_NONE = 0U,
        RESULT_CONVERT,
        RESULT_DELAY,
        RESULT_BREAK
    };
    Q_ENUM(ProcResult)

    typedef FPMap::ProcResult (FPMap::*EventProcFunc)(HMI_EVENT &event);

    ProcResult entryFunction(HMI_EVENT &event);

signals:

public slots:

private:
    void initEventProcFunctionTable(void);

    ProcResult procFunction_TestA(HMI_EVENT &event);
    ProcResult procFunction_TestB(HMI_EVENT &event);
    ProcResult procFunction_TestC(HMI_EVENT &event);
    ProcResult procFunction_TestD(HMI_EVENT &event);
    ProcResult procFunction_TestE(HMI_EVENT &event);

private:
    // Event PreProcess Function Pointer Table
    QHash<quint32, EventProcFunc> m_EventPreProcessTable;
};

#endif // FPMAP_H
