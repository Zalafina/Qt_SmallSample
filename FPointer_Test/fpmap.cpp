#include <QTimer>
#include <QDebug>
#include <string.h>
#include "fpmap.h"

using namespace std;

const SubrutineFunc FPMap::SubSAT_tbl[] =
{
    static_cast<SubrutineFunc>(&FPMap::SubrutineFunc_TestA),
    static_cast<SubrutineFunc>(&FPMap::SubrutineFunc_TestB),
    static_cast<SubrutineFunc>(&FPMap::SubrutineFunc_TestC),
    static_cast<SubrutineFunc>(&FPMap::SubrutineFunc_TestD),
    static_cast<SubrutineFunc>(&FPMap::SubrutineFunc_TestE),
    static_cast<SubrutineFunc>(&FPMap::SubrutineFunc_TestF),
    static_cast<SubrutineFunc>(&FPMap::SubrutineFunc_TestG),
};

FPMap::FPMap(QObject *parent) : QObject(parent)
{
    initEventProcFunctionTable();
}

//FPMap::ProcResult FPMap::entryFunction(HMI_EVENT &event)
//{
//    Q_UNUSED(event)
//    qDebug() << "entryFunction():" << event.eventId;
//    return RESULT_NONE;
//}

quint8 FPMap::entryFunction(HMI_EVENT &event)
{
    Q_UNUSED(event)
    qDebug() << "entryFunction():" << event.eventId;
    return 0xfeU;
}

void FPMap::start()
{
    quint32 table_size = sizeof(SubSAT_tbl)/sizeof(SubrutineFunc);
    qDebug() << "SubSAT_tbl size = " << table_size;

    QTimer::singleShot(3000, [=] () {
        HMI_EVENT event;

        for(quint16 loop = FPOINTER_SPID_START; loop < FPOINTER_SPID_END; loop++){
            //ProcResult proc_result = RESULT_NONE;
            quint8 proc_result = 0xffU;
            event.eventId = (quint32)loop;

            if (m_EventPreProcessTable.find(loop) != m_EventPreProcessTable.end()){
            //if (true == m_EventPreProcessTable.contains(loop)){
                //FPMap_EventProcFunc eventProcFuncPtr = (FPMap_EventProcFunc)m_EventPreProcessTable.value(loop);
                SubrutineFunc eventProcFuncPtr = m_EventPreProcessTable.at(loop);
                proc_result = (this->*(eventProcFuncPtr))();
            }
            else{
                // Do Nothing
            }

            //SubrutineFunc SubrutineFuncPtr = SubSAT_tbl[loop];
            proc_result = (this->*(SubSAT_tbl[loop]))();
        }
    });
}

void FPMap::initEventProcFunctionTable(void)
{
//    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTA     ,   (EventProcFunc)&FPMap::entryFunction        ));
//    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTB     ,   (EventProcFunc)&FPMap::entryFunction        ));
//    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTC     ,   (EventProcFunc)&FPMap::entryFunction        ));
//    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTD     ,   (EventProcFunc)&FPMap::entryFunction        ));
//    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTE     ,   (EventProcFunc)&FPMap::entryFunction        ));

    static_cast<void>(m_EventPreProcessTable.insert(pair<quint16, SubrutineFunc>(FPOINTER_SPID_TESTA     ,   (SubrutineFunc)&FPMap::SubrutineFunc_TestA        )));
    static_cast<void>(m_EventPreProcessTable.insert(pair<quint16, SubrutineFunc>(FPOINTER_SPID_TESTB     ,   (SubrutineFunc)&FPMap::SubrutineFunc_TestB        )));
    static_cast<void>(m_EventPreProcessTable.insert(pair<quint16, SubrutineFunc>(FPOINTER_SPID_TESTC     ,   (SubrutineFunc)&FPMap::SubrutineFunc_TestC        )));
    static_cast<void>(m_EventPreProcessTable.insert(pair<quint16, SubrutineFunc>(FPOINTER_SPID_TESTD     ,   (SubrutineFunc)&FPMap::SubrutineFunc_TestD        )));
    static_cast<void>(m_EventPreProcessTable.insert(pair<quint16, SubrutineFunc>(FPOINTER_SPID_TESTE     ,   (SubrutineFunc)&FPMap::SubrutineFunc_TestE        )));
    static_cast<void>(m_EventPreProcessTable.insert(pair<quint16, SubrutineFunc>(FPOINTER_SPID_TESTF     ,   (SubrutineFunc)&FPMap::SubrutineFunc_TestF        )));
    static_cast<void>(m_EventPreProcessTable.insert(pair<quint16, SubrutineFunc>(FPOINTER_SPID_TESTG     ,   (SubrutineFunc)&FPMap::SubrutineFunc_TestG        )));
}

quint8 FPMap::SubrutineFunc_TestA()
{
    qDebug() << __FUNCTION__ << " Called.";
    return 0xfeU;
}

quint8 FPMap::SubrutineFunc_TestB()
{
    qDebug() << __FUNCTION__ << " Called.";
    return 0xfeU;
}

quint8 FPMap::SubrutineFunc_TestC()
{
    qDebug() << __FUNCTION__ << " Called.";
    return 0xfeU;
}

quint8 FPMap::SubrutineFunc_TestD()
{
    qDebug() << __FUNCTION__ << " Called.";
    return 0xfeU;
}

quint8 FPMap::SubrutineFunc_TestE()
{
    qDebug() << __FUNCTION__ << " Called.";
    return 0xfeU;
}

quint8 FPMap::SubrutineFunc_TestF()
{
    qDebug() << __FUNCTION__ << " Called.";
    return 0xfeU;
}

quint8 FPMap::SubrutineFunc_TestG()
{
    qDebug() << __FUNCTION__ << " Called.";
    return 0xfeU;
}
