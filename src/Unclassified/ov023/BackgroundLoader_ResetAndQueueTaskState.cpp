#include <globaldefs.h>
ARM
extern "C" bool BackgroundLoader_RemoveTaskAndResetLoadState(void*);
extern "C" void func_ov023_021f5340(void*);
extern "C" void* memset(void*, int, unsigned);
// Original: arm9/ov023 @ 0x021F52F8; symbol: func_ov023_021f52f8; size: 0x48.
extern "C" void BackgroundLoader_ResetAndQueueTaskState(void* state, unsigned value) {
    BackgroundLoader_RemoveTaskAndResetLoadState(state);
    memset(state, 0, 0xc);
    *(unsigned*)( (char*)state + 0x10) = -1;
    BackgroundLoader_RemoveTaskAndResetLoadState(state);
    *(unsigned*)((char*)state + 0x14) = value;
    *(unsigned short*)((char*)state + 0xc) = 1;
    func_ov023_021f5340(state);
}
