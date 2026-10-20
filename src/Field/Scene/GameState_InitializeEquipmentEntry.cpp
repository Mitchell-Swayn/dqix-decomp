#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void Memory_ResetSafeAllocatorState(void*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*, unsigned int);
// Original: arm9/ov017 @ 0x021BAC24; symbol: func_ov017_021bac24; size: 0x34.
extern "C" void GameState_InitializeEquipmentEntry(void* p) {
    _ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
    TextContext_GetSharedInstance();
    Memory_ResetSafeAllocatorState(*(void**)((char*)p + 0x3728));
    char* base = (char*)p + 0x3000;
    LinkedQueue_AppendAndMarkActive(*(unsigned int**)(base + 0x6fc), *(unsigned int*)(base + 0x728));
}
