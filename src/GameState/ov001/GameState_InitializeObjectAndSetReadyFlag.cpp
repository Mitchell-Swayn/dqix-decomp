#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov001_02165880[];
extern "C" void Object_ResetMotionStateAndChildRecords(void *);
struct GlobalReady { unsigned char pad[0xE4]; unsigned int value; };
extern "C" GlobalReady data_ov001_021658b8;
// Original: arm9/ov001 @ 0x0215D134; symbol: func_ov001_0215d134; size: 0x34.
extern "C" int GameState_InitializeObjectAndSetReadyFlag(void) {
    Object_ResetMotionStateAndChildRecords(*(void **)(data_ov001_02165880 + 0x24));
    if (data_ov001_021658b8.value == 0) {
        data_ov001_021658b8.value = 1;
    }
    return 1;
}
