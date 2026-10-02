#include <globaldefs.h>
#include <std_library_functions.h>
#include "CombatActionRecords.h"

extern "C" {

ARM void func_ov000_0215fe64(CombatActionPayload* record) {
    memset(record, 0, sizeof(*record));
    record->identifier = -1;
}

ARM void func_ov000_0215fe84(CombatActionPayload* record, CombatResultNode* result, int list) {
    CombatResultNode** link = &record->resultHeads[list];
    while (*link != NULL) link = &(*link)->next;
    *link = result;
    ++record->resultCounts[list];
}

ARM CombatResultNode* func_ov000_0215feb4(CombatActionPayload* record, int index, int list) {
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
