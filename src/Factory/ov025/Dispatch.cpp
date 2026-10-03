#include "../ov000/CombatActionRecords.h"

// Only the fields accessed by these routines have established meanings.
struct DispatchRequest { CombatActionGroup* record; int mode; int kind; int index; int ordinal; unsigned char flags; };
extern "C" {
void __clear(void*, unsigned int);
CombatActionRecord* func_ov000_02160094(CombatActionGroup*, int);
CombatTargetRecord* func_ov000_021600f8(CombatActionGroup*, int);
void func_ov025_021d8c30(void*, CombatActionGroup*, int, int, int, int, int);
void func_ov025_021d8ab8(void*, CombatActionGroup*, int, int, int);
void func_ov025_021d8a40(void* context, CombatActionGroup* record)
{
    int counts[2] = { record->targetCount, record->actionCount };
    for (int group = 0; group < 2; ++group) {
        for (int i = 0; i < counts[group]; ++i)
            func_ov025_021d8ab8(context, record, 1, 6, group);
    }
}
void func_ov025_021d8ab8(void* context, CombatActionGroup* record, int mode, int kind, int index)
{
    int counts[6];
    __clear(counts, sizeof(counts));
    int* values = counts;
    if (mode == 0) {
        CombatActionRecord* entry = func_ov000_02160094(record, index);
        if (entry) {
            values[0] = entry->payload.resultCounts[0]; values[1] = entry->payload.resultCounts[2];
            values[2] = entry->payload.resultCounts[3]; values[3] = entry->payload.resultCounts[5];
            values[4] = entry->payload.resultCounts[4]; values[5] = entry->payload.resultCounts[1];
        }
    } else if ((unsigned int)(mode - 1) <= 2) {
        CombatTargetRecord* entry = func_ov000_021600f8(record, index);
        if (entry) {
            values[0] = entry->payload.resultCounts[0];
            values[1] = entry->payload.resultCounts[1];
            values[2] = entry->payload.resultCounts[2];
        }
    }
    if (kind == 6) {
        for (int group = 0; group < 6; ++group)
            for (int i = 0; i < values[group]; ++i)
                func_ov025_021d8c30(context, record, mode, group, index, i, 0);
    } else {
        for (int i = 0; i < values[kind]; ++i)
            func_ov025_021d8c30(context, record, mode, kind, index, i, 0);
    }
}
void func_ov025_021d8bfc(void* context, const DispatchRequest* request)
{
    func_ov025_021d8c30(context, request->record, request->mode, request->kind,
                      request->index, request->ordinal, request->flags);
}
}
