#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* GameState_ReadUnknownB0(void* state);
extern "C" int Input_TestKeyMask(unsigned short* keys, unsigned short mask);
extern "C" void SetField238Enabled(int object);
extern "C" void ClearWordFieldAtOffset238(int object);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov015 @ 0x021925A8; symbol: func_ov015_021925a8; size: 0x58.
extern "C" int Input_UpdateField238FromKeyMask(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    if (state == 0)
        return 0;
    void* object = GameState_ReadUnknownB0(state);
    if (object == 0)
        return 0;
    if (Input_TestKeyMask(&data_02114e30, 0xc00)) {
        SetField238Enabled((int)object);
        return 1;
    }
    ClearWordFieldAtOffset238((int)object);
    return 0;
}
