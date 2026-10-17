#include <globaldefs.h>
ARM
extern "C" void Ov003_ProcessFixedRegionInChunks(void*, bool);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(void*);
// Original: arm9/ov003 @ 0x021716F8; symbol: func_ov003_021716f8; size: 0x6C.
extern "C" void Graphics_AdvanceTimedOwnerState(void* self) {
    if (*(void**)((char*)self + 0x724) != 0) {
        bool enabled = ((unsigned)*(unsigned*)((char*)self + 0x34C) >> 31) != 0;
        Ov003_ProcessFixedRegionInChunks(self, enabled);
        *(unsigned char*)self = 3;
    }
    unsigned delta = _ZNK9GameState21GetEffectiveDeltaTimeEv(_ZN9GameState11GetInstanceEv());
    unsigned elapsed = *(unsigned*)((char*)self + 0x72C) + delta;
    *(unsigned*)((char*)self + 0x72C) = elapsed;
    if (elapsed > 0xBB8) {
        WaitForStateThreeThenProcessOwnerWithTimeout(Object_GetGlobalConnectionState());
        *(unsigned char*)self = 4;
    }
}
