#pragma opt_propagation off
#pragma opt_common_subs off
#include "System/Interrupts.h"
#include "System/BiosData.h"
#include "System/DTCM.h"
#include <globaldefs.h>

#pragma optimize_for_size off

// Original: arm9/main @ 0x020C6954; symbol: _Z16WaitForInterruptbj; size: 0x74.
void WaitForInterrupt(bool onlySubsequent, unsigned int mask)
{
    int priorState = DisableIRQInterrupts();
    if (onlySubsequent) {
        DTCMData* dtcm = &Entry_UnknownRoleProcedureReferenceRecords;
        dtcm->interruptsFired &= ~mask;
    }
    SetIRQInterruptState(priorState);

    DTCMData* dtcm = &Entry_UnknownRoleProcedureReferenceRecords;
    if (mask & dtcm->interruptsFired) return;
    BlockedContextList* list = &Entry_UnknownRoleProcedureReferenceRecords.block_60;
    unsigned int* fired = &dtcm->interruptsFired;
    do {
        BlockCurrentContext(list);
    } while (!(mask & *fired));
}
