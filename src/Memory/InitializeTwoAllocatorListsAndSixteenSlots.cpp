#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Slot {
    SignedAllocatorHeader header;
    unsigned char unknown_24[8];
    unsigned char unknown_2c;
    unsigned char unknown_2d[0xf];
    unsigned char index;
    unsigned char unknown_3d[7];
};

struct Channel {
    SignedAllocatorList listA;
    SignedAllocatorList listB;
    int unknown_18;
    int unknown_1c;
    unsigned char unknown_20;
    unsigned char unknown_21[3];
};

extern "C" {
// Original data: arm9/main @ 0x210f3cc; symbol: data_0210f3cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SignedAllocatorList InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SignedAllocatorList SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x210f3e4; symbol: data_0210f3e4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1088 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Slot InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage_Variant2[16];
// Original data: arm9/main @ 0x210f824; symbol: data_0210f824.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Channel AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage[32];
}

// Original: arm9/main @ 0x020BC23C; symbol: func_020bc23c; size: 0xB4.
extern "C" ARM void InitializeTwoAllocatorListsAndSixteenSlots() {
    SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.Initialize(0x14);
    InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage.Initialize(0x14);
    int i;
    Slot* slot = InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage_Variant2;
    i = 0;
    do {
        slot->unknown_2c = 0;
        slot->index = i;
        InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage.InsertAtEnd(&slot->header);
        slot++;
    } while (++i < 16);
    Channel* channel = AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage;
    int j = 0;
    do {
        channel->listA.Initialize(0xc);
        channel->listB.Initialize(0);
        channel->unknown_20 = 0x7f;
        channel->unknown_18 = 1;
        channel->unknown_1c = 0;
        channel++;
    } while (++j < 32);
}
