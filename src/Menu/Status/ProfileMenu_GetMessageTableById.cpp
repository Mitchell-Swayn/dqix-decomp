#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void* Menu_GetRecordMessageTable(void*);
extern "C" int BattleAI_BoostDamageEstimatesForTargetTypeTwelve(void*);
// Original: arm9/ov004 @ 0x02168B08; symbol: func_ov004_02168b08; size: 0x3C.
extern "C" void* ProfileMenu_GetMessageTableById(void* self, unsigned value) {
    void* state = Menu_GetDisplayRecordRegistry(self);
    void* result = MenuRecordList_LocateByKey(state, value);
    if (result != 0 && MenuRecord_GetType(result) == 4)
        return Menu_GetRecordMessageTable(result);
    return 0;
}
