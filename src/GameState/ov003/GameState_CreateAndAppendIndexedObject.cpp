#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *_ZN9GameState14GetProtagonistEv();
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" void InitializeSafeAllocatorObject(unsigned char *object);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *p, unsigned int n);

// Original: arm9/ov003 @ 0x0217E300; symbol: func_ov003_0217e300; size: 0x34.
extern "C" void GameState_CreateAndAppendIndexedObject(unsigned char *state) {
    _ZN9GameState11GetInstanceEv();
    _ZN9GameState14GetProtagonistEv();
    ReadWordFieldAtOffset1C();
    InitializeSafeAllocatorObject(*(unsigned char **)(state + 0x3730));
    AppendLinkedNodeAndMarkActive(*(unsigned int **)(state + 0x36fc), *(unsigned int *)(state + 0x3730));
}
