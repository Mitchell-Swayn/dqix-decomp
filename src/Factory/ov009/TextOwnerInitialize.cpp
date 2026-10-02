#include "TextOwner.h"
extern "C" {
void* func_020d6c00();
void func_020466e4(void*, int);
void func_020dfc40(void*);
void func_ov009_021847ec(TextPatternContext*);
void func_0204af64(void*);
void func_0205cfd4(void*);
void func_0204c684(void*);
void func_0205bef8(void*);
int func_020424e4(const char*, int);
extern char data_ov009_0218aca4[];
}

extern "C" void func_ov009_0218454c(TextOwner* owner, int category, int mode)
{
    if ((owner->mode = mode) == 1) func_020466e4(func_020d6c00(), 15);
    owner->arenas[0].ResetAllocatorPointer();
    owner->arenas[1].ResetAllocatorPointer();
    owner->arenas[2].ResetAllocatorPointer();
    owner->arenas[3].ResetAllocatorPointer();
    owner->arenas[4].ResetAllocatorPointer();
    owner->arenas[5].ResetAllocatorPointer();
    owner->arenas[6].ResetAllocatorPointer();
    owner->arenas[7].ResetAllocatorPointer();
    owner->arenas[8].ResetAllocatorPointer();
    owner->auxiliaryArena = 0;
    owner->pairArenas = 0;
    owner->resourceA = 0;
    owner->resourceB = 0;
    owner->zoneState.Reset();
    func_020dfc40(&owner->resourceTable);
    owner->unknown_f8 = 0;
    func_ov009_021847ec(&owner->pattern);
    func_0204af64(owner->widgets[0]);
    func_0204af64(owner->widgets[1]);
    func_0204af64(owner->widgets[2]);
    func_0204af64(owner->widgets[3]);
    func_0204af64(owner->widgets[4]);
    func_0204af64(owner->widgets[5]);
    func_0205cfd4(owner->controllers[0]);
    func_0205cfd4(owner->controllers[1]);
    for (int i = 0; i < 1; ++i) func_0204c684(owner->primaryElements[i]);
    for (int i = 0; i < 4; ++i) func_0204c684(owner->secondaryElements[i]);
    owner->unknown_7d0 = 0;
    owner->unknown_7d4 = 0;
    owner->buffers[0] = 0;
    owner->buffers[1] = 0;
    owner->buffers[2] = 0;
    owner->buffers[3] = 0;
    owner->buffers[4] = 0;
    owner->buffers[5] = 0;
    owner->handles[0] = 0;
    owner->handles[1] = 0;
    owner->handles[2] = 0;
    owner->handles[3] = 0;
    owner->handles[4] = 0;
    owner->handles[5] = 0;
    owner->objectA.Initialize();
    owner->objectB.Initialize();
    func_0205bef8(owner->unknown_bec);
    func_ov009_021847c4(&owner->selectionIndices);
    owner->selectedIds[0] = -1;
    owner->selectedIds[1] = -1;
    owner->selectedIds[2] = -1;
    owner->selectedIds[3] = -1;
    owner->selectedIds[4] = -1;
    owner->selectedIds[5] = -1;
    owner->state = 0;
    owner->substate = 0;
    owner->unknown_d84 = 0;
    owner->controllerResult = 0;
    owner->unknown_d88 = 0;
    owner->unknown_d8c = -1;
    owner->unknown_d90 = 0;
    owner->unknown_d94 = 0;
    owner->unknown_d96 = 0;
    owner->unknown_d98 = 0;
    memset(&owner->flags, 0, 4);
    for (int i = 0; i < 2; ++i) owner->enabled[i] = 1;
    owner->category = category;
    owner->selectedTextBuffer = 0;
    for (int i = 0; i < 2; ++i) {
        owner->pairs[0][i] = 0;
        owner->pairs[1][i] = 0;
        owner->pairs[2][i] = 0;
        owner->pairs[3][i] = 0;
        owner->pairs[4][i] = 0;
        owner->pairs[5][i] = 0;
    }
    owner->textBuffers = 0;
    owner->wildcard = func_020424e4(data_ov009_0218aca4, 0);
    owner->unknown_db6 = 0;
}
