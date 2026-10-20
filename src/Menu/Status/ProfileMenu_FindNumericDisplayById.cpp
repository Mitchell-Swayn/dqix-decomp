#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" int BattleAI_BoostDamageEstimatesForTargetTypeTwelve(void*);
// Original: arm9/ov004 @ 0x02168A38; symbol: func_ov004_02168a38; size: 0x34.
extern "C" void* ProfileMenu_FindNumericDisplayById(void* self, unsigned value) {
    void* state = Menu_GetDisplayRecordRegistry(self);
    void* result = MenuRecordList_LocateByKey(state, value);
    if (result != 0) {
        if (MenuRecord_GetType(result) == 0xf) return result;
    }
    return 0;
}
