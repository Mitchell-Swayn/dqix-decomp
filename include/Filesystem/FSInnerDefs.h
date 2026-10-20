#pragma once

#include "NitroVM.h"
#include "LowNitroHandle.h"
#include "FileAccessor.h"
#include "CardReadManager.h"
#include "System/ProcessorContext.h"

#if defined(jpn)
#define CardReadManager_ReadGlobalStatus func_020d2c64

#define OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 data_02110fa4

#define NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage data_021113c8
#define SetROMFilesystemRoot_UnknownRoleZeroInitializedStorage data_021113cc
#define InitializeROMFilesystem_UnknownRoleZeroInitializedStorage data_021113d8
#define ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage data_021113dc
#define ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2 data_021113f4
#define InitializeCardReadManager_UnknownRoleZeroInitializedStorage data_02111520
#define TryReadViaDMA_UnknownRoleZeroInitializedStorage data_02111580
#define InitializeCardReading_UnknownRoleZeroInitializedStorage data_02111ba0
#endif

extern "C"
{
    CBool CardReadManager_ReadGlobalStatus();
}

#define GET_FLAG_BIT(what, idx) (((what) & (1 << (idx))) ? 1 : 0)

struct Struct_02111728
{
    NitroHandle* firstHandle;
    NitroDirectoryAccessor romFSRoot;
};

struct Struct_0211173c
{
    unsigned int busHolderID;
    unsigned int dmaChannel;

    // For each overlay we have 0x20 bytes of metadata in the ROM.
    // The ARM9 overlays are all grouped together in a table, and the ARM7 overlays
    // are grouped together in another table. (In DQIX there are no arm7 overlays)
    // In theory, one or both of these tables could be loaded into memory,
    // in which case this would point to it. In practice, I don't think it ever is
    struct ArmOverlayDataTableData
    {
        void* start;
        unsigned int size;
    };
    ArmOverlayDataTableData arm9Data;
    ArmOverlayDataTableData arm7Data;
};

struct Struct_02111f20
{
    typedef void (*LowLevelReadProc)(Struct_02111f20*);

    LowLevelReadProc lowLevelReadProc;
    unsigned int control_4;
    unsigned int* alignedWrite;
    unsigned int unknown_C[5]; // might be padding
    // 512 = 0x200 bytes of temporary space for unaligned writes
    unsigned char scratchBuffer[512];
};

struct Struct_02111f00
{
    unsigned int number;
    unsigned int unknown_4[7];
    Struct_02111f20 innerStruct;
};

// Original data: arm9/main @ 0x2111728; symbol: data_02111728.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Struct_02111728 NitroHandleFindBySignature_UnknownRoleZeroInitializedStorage;
// The directory overlaps the registry at +4. These registry declarations still
// refer to original fallback storage; a member macro changes matched codegen.
// Original data: arm9/main @ 0x211172c; symbol: data_0211172c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern NitroDirectoryAccessor SetROMFilesystemRoot_UnknownRoleZeroInitializedStorage;

// Original data: arm9/main @ 0x2111738; symbol: data_02111738.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int InitializeROMFilesystem_UnknownRoleZeroInitializedStorage; // stores whether the rom fs is initialised
// Extra data for cartridge filesystem
// Original data: arm9/main @ 0x211173c; symbol: data_0211173c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Struct_0211173c ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage;
// Handle for the cartridge filesystem
// Original data: arm9/main @ 0x2111754; symbol: data_02111754.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 92 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern NitroHandle ChangeROMLoadDMAChannel_UnknownRoleZeroInitializedStorage_Variant2;

// Original data: arm9/main @ 0x2111880; symbol: data_02111880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Arm7CardReadData InitializeCardReadManager_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x21118e0; symbol: data_021118e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1568 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern CardReadManager TryReadViaDMA_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2111f00; symbol: data_02111f00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 576 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Struct_02111f00 InitializeCardReading_UnknownRoleZeroInitializedStorage;
//extern Struct_02111f20 data_02111f20;
