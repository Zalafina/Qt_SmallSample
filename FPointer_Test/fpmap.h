#ifndef FPMAP_H
#define FPMAP_H

#include <QObject>
#include <QHash>

typedef struct stHMIEvent {
    quint32     eventId;
    quint32     param;
    quint32     param_Ex[4];
} HMI_EVENT;

enum
{
    FPOINTER_SPID_START,
    FPOINTER_SPID_TESTA = FPOINTER_SPID_START,
    FPOINTER_SPID_TESTB,
    FPOINTER_SPID_TESTC,
    FPOINTER_SPID_TESTD,
    FPOINTER_SPID_TESTE,
    FPOINTER_SPID_TESTF,
    FPOINTER_SPID_TESTG,
    FPOINTER_SPID_END
};

typedef quint8 (QObject::*SubrutineFunc)(void);

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

    //typedef quint8 (FPMap::*FPMap_EventProcFunc)(HMI_EVENT &event);
    //typedef quint8 (QObject::*SubrutineFunc)(void);

//    ProcResult entryFunction(HMI_EVENT &event);
    quint8 entryFunction(HMI_EVENT &event);

    void start();

    static const SubrutineFunc SubSAT_tbl[];

signals:

public slots:

private:
    void initEventProcFunctionTable(void);

    ProcResult procFunction_TestA(HMI_EVENT &event);
    ProcResult procFunction_TestB(HMI_EVENT &event);
    ProcResult procFunction_TestC(HMI_EVENT &event);
    ProcResult procFunction_TestD(HMI_EVENT &event);
    ProcResult procFunction_TestE(HMI_EVENT &event);

    quint8 SubrutineFunc_TestA(void);
    quint8 SubrutineFunc_TestB(void);
    quint8 SubrutineFunc_TestC(void);
    quint8 SubrutineFunc_TestD(void);
    quint8 SubrutineFunc_TestE(void);
    quint8 SubrutineFunc_TestF(void);
    quint8 SubrutineFunc_TestG(void);

private:
    // Event PreProcess Function Pointer Table
    //QHash<quint16, EventProcFunc> m_EventPreProcessTable;
    std::map<quint16, SubrutineFunc> m_EventPreProcessTable;
};

#endif // FPMAP_H
