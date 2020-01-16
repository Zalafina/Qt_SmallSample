#include <QTimer>
#include <QDebug>
#include <string.h>
#include "fpmap.h"

FPMap::FPMap(QObject *parent) : QObject(parent)
{
    initEventProcFunctionTable();
}

FPMap::ProcResult FPMap::entryFunction(HMI_EVENT &event)
{
    Q_UNUSED(event)
    qDebug() << "entryFunction():" << event.eventId;
    return RESULT_NONE;
}

void FPMap::start()
{
    QTimer::singleShot(3000, [=] () {
        HMI_EVENT event;

        for(quint16 loop = FPOINTER_SPID_START; loop < FPOINTER_SPID_END; loop++){
            ProcResult proc_result = RESULT_NONE;
            event.eventId = (quint32)loop;

            if (true == m_EventPreProcessTable.contains(loop)){
                EventProcFunc eventProcFuncPtr = m_EventPreProcessTable.value(loop);
                proc_result = (this->*(eventProcFuncPtr))(event);
            }
            else{
                // Do Nothing
            }

        }
    });
}

void FPMap::initEventProcFunctionTable(void)
{
    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTA     ,   &FPMap::entryFunction        ));
    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTB     ,   &FPMap::entryFunction        ));
    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTC     ,   &FPMap::entryFunction        ));
    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTD     ,   &FPMap::entryFunction        ));
    static_cast<void>(m_EventPreProcessTable.insert(FPOINTER_SPID_TESTE     ,   &FPMap::entryFunction        ));
}
