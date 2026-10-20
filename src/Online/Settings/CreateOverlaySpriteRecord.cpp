#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022350BC; symbol: CreateOverlaySpriteRecord; size: 0xD8.
extern "C" void* Memory_AllocateZeroedBlock(unsigned, unsigned);
extern "C" void WfcUtility_WriteCoordinatePair(unsigned short, unsigned short, void*);
extern "C" void* WfcUtility_CreateSpriteGroupFromCellTemplate(unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetSpriteGroupPosition(void*, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetSpriteGroupPriority(void*, int, unsigned);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(void*, void*, void*, void*);
// Original data: arm9/ov031 @ 0x22491f0; symbol: data_ov031_022491f0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 100f0e00.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char CreateOverlaySpriteRecord_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcScrollbar_UpdateInputState(void);
extern "C" void CreateOverlaySpriteRecord(unsigned char a, unsigned char b, unsigned short c, unsigned short d, unsigned int e)
{
    *(unsigned char**)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage = (unsigned char*)Memory_AllocateZeroedBlock(0x20, 4);
    (*(unsigned char**)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage)[0x1b] = a;
    (*(unsigned char**)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage)[0x19] = b;
    (*(unsigned char**)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage)[0x1a] = e;
    WfcUtility_WriteCoordinatePair(c, d, *(unsigned char**)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage + 0x10);
    void* created = WfcUtility_CreateSpriteGroupFromCellTemplate(0, CreateOverlaySpriteRecord_UnknownRoleInitializedBytes[a], 1);
    **(void***)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage = created;
    WfcUtility_SetSpriteGroupPosition(**(void***)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage, (unsigned)-1, c, d + e);
    WfcUtility_SetSpriteGroupPriority(*(void**)*(unsigned int**)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage, -1, 1);
    *(void**)(*(unsigned char**)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage + 0xc) = WfcUtility_CreateTaskWithBorrowedContext((void*)0, (void*)WfcScrollbar_UpdateInputState, 0, (void*)0x80);
}
