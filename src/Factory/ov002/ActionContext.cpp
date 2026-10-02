#include "ActionContext.h"
#include "GameState/GameState.h"

extern "C" void* func_02010828(GameState*);
extern "C" void* func_0202ae18();
extern "C" bool func_0202b7d8(void*);
extern "C" int func_02086ef0(void*, int);
extern "C" void func_ov002_02153e90(ActionResult*);
extern "C" int func_ov002_02154a6c(void*, int, int);
extern "C" int func_ov002_02154b94(void*, int);
extern "C" int func_ov002_02154a34(void*, int);
extern "C" short func_ov002_021549c8(void*, int, int, ActionResult*);
extern "C" void func_ov017_021c9e00(int, int, int, int);

// The third callback argument is required but not inspected by this action.
extern "C" int func_ov002_02153ea4(void* dispatcher, ActionContext* context,
                                  void* itemRecord, int alternate)
{
    if (!context) return 0;
    if (!itemRecord) return 0;
    void* storage = func_02010828(GameState::GetInstance());
    void* state = func_0202ae18();
    int changed = 0;
    ActionResult* results = context->results;
    if (alternate) results = context->alternateResults;
    for (int i = 0; i < 4; ++i) func_ov002_02153e90(&results[i]);
    for (int i = 0; i < context->count; ++i) {
        ActionResult* result = &results[i];
        int member = context->members[i];
        if (!func_02086ef0(storage, member)) result->unavailable = 1;
        if (!func_ov002_02154a6c(dispatcher, member, context->owner)) {
            result->status = 1;
            continue;
        }
        if (func_ov002_02154b94(dispatcher, member)) {
            result->status = 2;
            continue;
        }
        if (!func_ov002_02154a34(dispatcher, member)) continue;
        if (result->unavailable) {
            result->value = 1;
            result->status = 3;
        } else {
            result->value = func_ov002_021549c8(dispatcher, member, 2, result);
        }
        if (result->status) {
            if (func_0202b7d8(state) && func_02086ef0(storage, member))
                func_ov017_021c9e00(member, 0, 0, 1);
            changed = 1;
        }
    }
    return changed;
}
