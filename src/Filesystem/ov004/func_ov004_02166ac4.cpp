#include <globaldefs.h>
ARM
extern "C" char data_ov004_0217101c[];
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" void* Object_GetGlobalRequestQueue();
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void* memcpy(void*, const void*, unsigned int);
// Original: arm9/ov004 @ 0x02166AC4; symbol: func_ov004_02166ac4; size: 0x7C.
extern "C" int func_ov004_02166ac4(void) {
    char* state = *(char**)data_ov004_0217101c;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(state + 0x44));
    *(int*)(state + 0x44) = -1;
    _ZN13SafeAllocator7DestroyEv(state + 0x30);
    _ZN13SafeAllocator7DestroyEv(state + 0x1c);
    char* sourceState = *(char**)data_ov004_0217101c;
    memcpy((char*)ReadGlobalValueAt02108844() + 0x2cc, sourceState + 0x51, 0x66);
    void* queue = Object_GetGlobalRequestQueue();
    char* queueState = *(char**)data_ov004_0217101c;
    *(void**)((char*)queue + 0xa0) = *(void**)(queueState + 0xb8);
    char* field = (char*)ReadWordFieldAtOffset1C();
    int zero = 0;
    field += 0x1000;
    *(volatile unsigned char*)(field + 0x962) = zero;
    return zero;
}
