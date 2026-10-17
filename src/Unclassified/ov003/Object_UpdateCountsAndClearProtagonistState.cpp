#include <globaldefs.h>
ARM
extern "C" void AddPositiveCountsFromEightObjectSlots(int);
extern "C" void GameState_AppendSerializedRecord(int, int);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(void*, int);
// Original: arm9/ov003 @ 0x02166F40; symbol: func_ov003_02166f40; size: 0x40.
extern "C" void Object_UpdateCountsAndClearProtagonistState(char* self) {
    int index = *(short*)(self + 0x482);
    AddPositiveCountsFromEightObjectSlots(index);
    index = *(short*)(self + 0x482);
    GameState_AppendSerializedRecord(index, 0);
    void* protagonist = _ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv());
    if (protagonist != 0) Object_ClearTwoStateFieldsAndOptionallyResetAnimation(protagonist, 1);
}
