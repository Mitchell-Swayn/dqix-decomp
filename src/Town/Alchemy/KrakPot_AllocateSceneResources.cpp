#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
ARM
extern "C" {
void ItemDetail_AllocateDisplayResources(void*, SafeAllocator*);
void Ov023_SetObjectFlagAndGlobalValue(void*, int);
void Menu_ResetLayout(void*);
void Graphics_InitializeCanvasTransferState(void*);
void TextCanvas_InitializeLayoutAndTransferDefaults(void*);
void DisplayLayout_Initialize(void*);
void Graphics_InitializeSpriteTransformDefaults(void*);
// Original data: arm9/ov006 @ 0x0215FF7C; symbol: data_ov006_0215ff7c.
// Six initialized arena sizes: 0x800, 0xc00, 0x1200, 0x200, 0x600, 0xa000.
// Original data and unresolved extent: docs/data-symbols/ov006.md.
extern unsigned KrakPotAllocateSceneResources_UnknownRoleInitializedBytes[];
}
#define P(offset) (*(unsigned char**)(self + (offset)))
#define A(offset) (*(SafeAllocator**)(self + (offset)))

// Original fallback callers can be weak; retain this entry point in its ROM range.
#pragma force_active on
// Original: arm9/ov006 @ 0x02154348; symbol: func_ov006_02154348; size: 0x2CC.
// Allocates scene, item detail and preview arenas, then initializes their embedded display records.
extern "C" void KrakPot_AllocateSceneResources(unsigned char* self, SafeAllocator* allocator, int mode)
{
    P(0x180) = (unsigned char*)allocator->Allocate(0x78);
    A(0x184) = (SafeAllocator*)allocator->Allocate(0x14);
    A(0x188) = (SafeAllocator*)allocator->Allocate(0x14);
    P(0x1c4) = (unsigned char*)allocator->Allocate(0x80);
    P(0x1c8) = (unsigned char*)allocator->Allocate(0x4c);
    P(0x1cc) = (unsigned char*)allocator->Allocate(0x40);
    P(0x1d0) = (unsigned char*)allocator->Allocate(0xe0);
    P(0x1d4) = (unsigned char*)allocator->Allocate(0x40);
    P(0x1e0) = (unsigned char*)allocator->Allocate(0x2a8);
    void* data = allocator->Allocate(0x258);
    A(0x184)->CreateTypeA(data, 0x258);
    data = allocator->Allocate(0x258);
    A(0x188)->CreateTypeA(data, 0x258);
    A(0x184)->Reset();
    A(0x188)->Reset();
    A(0x1280) = (SafeAllocator*)allocator->Allocate(0x14);
    A(0x1284) = (SafeAllocator*)allocator->Allocate(0x14);
    data = allocator->Allocate(0x1e00);
    A(0x1280)->CreateTypeA(data, 0x1e00);
    A(0x1280)->Reset();
    data = allocator->Allocate(0x80);
    A(0x1284)->CreateTypeA(data, 0x80);
    A(0x1284)->Reset();
    ItemDetail_AllocateDisplayResources(self + 0x2e4 + 0x800, A(0x1280));
    Ov023_SetObjectFlagAndGlobalValue(self + 0x2e4 + 0x800, mode);

    for (unsigned char i = 0; i < 6; ++i) {
        unsigned size = KrakPotAllocateSceneResources_UnknownRoleInitializedBytes[i];
        int offset = i * 0x14;
        data = allocator->Allocate(size);
        SafeAllocator* arena = (SafeAllocator*)(P(0x180) + offset);
        arena->CreateTypeA(data, size);
        ((SafeAllocator*)(P(0x180) + offset))->Reset();
    }
    unsigned char* previews = self + 0x284;
    for (unsigned char i = 0; i < 4; ++i) {
        ((SafeAllocator*)(previews + 0x800 + i * 0x14))->CreateTypeA(allocator->Allocate(0x280), 0x280);
        ((SafeAllocator*)(previews + 0x800 + i * 0x14))->Reset();
    }
    *P(0x1c4) = 0;
    Menu_ResetLayout(P(0x1c8));
    for (unsigned char i = 0; i < 2; ++i)
        Graphics_InitializeCanvasTransferState(P(0x1cc) + (i << 5));
    for (unsigned char i = 0; i < 1; ++i)
        TextCanvas_InitializeLayoutAndTransferDefaults(P(0x1d0) + i * 0xe0);
    DisplayLayout_Initialize(P(0x1d4));
    for (unsigned char i = 0; i < 17; ++i)
        Graphics_InitializeSpriteTransformDefaults(P(0x1e0) + i * 0x28);
}

#pragma force_active reset
