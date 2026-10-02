#include <globaldefs.h>
#include <std_library_functions.h>
#include "CombatTargetRecords.h"

extern "C" ARM void func_ov000_02157cdc(CombatTargetRecord* record) {
    memset(&record->payload, 0, sizeof(record->payload));
    memset(record->payload.targetIds, -1, sizeof(record->payload.targetIds));
    record->payload.identifier = -1;
    record->next = NULL;
}
