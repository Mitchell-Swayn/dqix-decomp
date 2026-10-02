#include <globaldefs.h>
#include <std_library_functions.h>
#include "CombatTargetRecords.h"

extern "C" {

ARM void func_ov000_0215fef0(CombatTargetPayload* record) {
    memset(record, 0, sizeof(*record));
    memset(record->targetIds, -1, sizeof(record->targetIds));
    record->identifier = -1;
}

// Both entry points append the same target pair; caller intent differs.
ARM void func_ov000_0215ff20(CombatTargetPayload* record, short id, unsigned char value) {
    if (record->targetCount >= 3) return;
    record->targetIds[record->targetCount] = id;
    record->targetValues[record->targetCount] = value;
    ++record->targetCount;
}

ARM void func_ov000_0215ff50(CombatTargetPayload* record, short id, unsigned char value) {
    if (record->targetCount >= 3) return;
    record->targetIds[record->targetCount] = id;
    record->targetValues[record->targetCount] = value;
    ++record->targetCount;
}

ARM int func_ov000_0215ff80(CombatTargetPayload* record, int index) {
    if (index >= 3) return -1;
    if (index < 0) return -1;
    return record->targetIds[index];
}

ARM int func_ov000_0215ffa0(CombatTargetPayload* record) {
    int index = record->targetCount - 1;
    if (record->targetCount > 3) index = 2;
    if (record->targetCount == 0) index = 0;
    return record->targetIds[index];
}

ARM void func_ov000_0215ffc4(CombatTargetPayload* record, CombatResultNode* result, int list) {
    CombatResultNode** link = &record->resultHeads[list];
    while (*link != NULL) link = &(*link)->next;
    *link = result;
    ++record->resultCounts[list];
}

ARM CombatResultNode* func_ov000_0215fff4(CombatTargetPayload* record, int index, int list) {
    if (record->resultCounts[list] <= index) return NULL;
    CombatResultNode* node = record->resultHeads[list];
    int current = 0;
    while (current < index && node != NULL) {
        node = node->next;
        ++current;
    }
    return node;
}

}
