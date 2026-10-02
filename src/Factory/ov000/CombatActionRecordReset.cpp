#include <globaldefs.h>
#include <std_library_functions.h>
#include "CombatActionRecords.h"

extern "C" ARM void func_ov000_02157d14(CombatActionRecord* record) {
    memset(&record->payload, 0, sizeof(record->payload));
    record->payload.identifier = -1;
    record->next = NULL;
}
