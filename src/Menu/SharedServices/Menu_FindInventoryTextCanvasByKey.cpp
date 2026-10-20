#include <globaldefs.h>
ARM
struct State;
extern "C" void *Menu_GetDisplayRecordRegistry(State *self);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned int MenuRecord_GetType(void *);
extern "C" int BattleAI_BoostDamageEstimatesForTargetTypeTwelve(void *self);
// Original: arm9/ov004 @ 0x02156F6C; symbol: func_ov004_02156f6c; size: 0x34.
extern "C" void *Menu_FindInventoryTextCanvasByKey(State *self, unsigned int id) {
    void *current = Menu_GetDisplayRecordRegistry(self);
    void *result = MenuRecordList_LocateByKey(current, id);
    if (result != 0 && MenuRecord_GetType(result) == 6) {
        return result;
    }
    return 0;
}
