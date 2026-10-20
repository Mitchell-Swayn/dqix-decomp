#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
// Original: arm9/ov003 @ 0x02153874; symbol: func_ov003_02153874; size: 0x6C.
extern "C" ARM void Alltrades_CancelVocationPreviewLoads(void* state) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    if (*(int*)((char*)state + 0x50) >= 0) _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)((char*)state + 0x50));
    if (*(int*)((char*)state + 0x54) >= 0) _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)((char*)state + 0x54));
    *(int*)((char*)state + 0x14) = 0;
    *(int*)((char*)state + 0x10) = 0;
    *(int*)((char*)state + 0x50) = -1;
    *(int*)((char*)state + 0x54) = -1;
    *((unsigned char*)state + 0x5a) = 2;
    *((unsigned char*)state + 0x5b) = 0;
    *((unsigned char*)state + 0x5c) = 0;
    *((unsigned char*)state + 0x5d) &= ~2;
    (void)loader;
}
