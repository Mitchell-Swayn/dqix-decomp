#include <globaldefs.h>
#include <std_library_functions.h>
#include "CombatActionRecords.h"

extern "C" {

ARM void func_ov000_02160030(CombatActionGroup* record) {
    memset(record, 0, sizeof(*record));
    record->identifier = -1;
    memset(&record->values, 0, sizeof(record->values));
    record->values.value = 0;
}

ARM void func_ov000_02160068(CombatActionGroup* record, CombatActionRecord* action) {
    CombatActionRecord** link = &record->actionHead;
    while (*link != NULL) link = &(*link)->next;
    *link = action;
    ++record->actionCount;
}

ARM CombatActionRecord* func_ov000_02160094(CombatActionGroup* record, int index) {
    if (record->actionCount <= index) return NULL;
    CombatActionRecord* node = record->actionHead;
    int current = 0;
    while (current < index && node != NULL) {
        node = node->next;
        ++current;
    }
    return node;
}

ARM void func_ov000_021600cc(CombatActionGroup* record, CombatTargetRecord* target) {
    CombatTargetRecord** link = &record->targetHead;
    while (*link != NULL) link = &(*link)->next;
    *link = target;
    ++record->targetCount;
}

ARM CombatTargetRecord* func_ov000_021600f8(CombatActionGroup* record, int index) {
    if (record->targetCount <= index) return NULL;
    CombatTargetRecord* node = record->targetHead;
    int current = 0;
    while (current < index && node != NULL) {
        node = node->next;
        ++current;
    }
    return node;
}

}
