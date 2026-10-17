#include <globaldefs.h>
ARM
extern "C" int Network_StartExtendedScan(void* fn, void* object);
extern "C" void* data_ov031_02290cf8;
extern "C" int func_ov031_022359e0();
// Original: arm9/ov031 @ 0x022358B4; symbol: func_ov031_022358b4; size: 0x34.
extern "C" int GameState_IsCallbackStateReady(void) {
    int result = Network_StartExtendedScan((void*)func_ov031_022359e0,
        (char*)data_ov031_02290cf8 + 0x1648);
    return result == 2;
}
