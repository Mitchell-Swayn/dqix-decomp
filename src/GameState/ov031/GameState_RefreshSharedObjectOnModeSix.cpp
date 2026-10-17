#include <globaldefs.h>
ARM
extern "C" void SetStateWithTransitionCallbacks(int value);
extern "C" int ForwardRecordQuery(void* p);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned value);
extern "C" char data_ov031_02290d18[];
// Original: arm9/ov031 @ 0x02239A24; symbol: func_ov031_02239a24; size: 0x50.
extern "C" int GameState_RefreshSharedObjectOnModeSix(void) {
    void* object = *(void**)(data_ov031_02290d18 + 4);
    if (*(unsigned*)((char*)object + 0x40) != 6)
        return 0;
    SetStateWithTransitionCallbacks(3);
    int result = ForwardRecordQuery((char*)*(void**)(data_ov031_02290d18 + 4) + 0x1e00);
    if (result == 2)
        return 1;
    SetSharedObjectWord54UnlessStateNineOrTen(result);
    return 0;
}
