#include <globaldefs.h>
#include <Filesystem/GPC.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

ARM
// The original keeps the zero table offset as an opaque register value and sums it
// unfolded into the copied length; both transformations are disabled to match.
#pragma opt_propagation off
#pragma opt_arithtransformation off

extern "C" {
// Original BSS: arm9/main @ 0x0210783C; symbol: data_0210783c.
// SafeAllocator object over a 0x400-byte block; reset after loading, then attached to
// the text context at +0x2D4.
extern unsigned char TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage[];
// Original BSS: arm9/main @ 0x02107800; symbol: data_02107800.
// Shared text resource table; see TextSharedResources.
extern unsigned char TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x020F000B; symbol: data_020f000b. "/data/ani/windata3.bncg".
extern char Text_InitializeSharedContextAndResources_TextDataAniWindata3Bncg[];
// Original data: arm9/main @ 0x020F0023; symbol: data_020f0023. "/data/pack_lv5/font_lv5.gp2".
extern char Text_InitializeSharedContextAndResources_TextDataPackLv5FontLv5Gp2[];
// Original data: arm9/main @ 0x020F003F; symbol: data_020f003f. "f8.mes".
extern char Text_InitializeSharedContextAndResources_TextF8Mes[];
// Original BSS: arm9/itcm @ 0x01FF9740; 0x3C00-byte ITCM storage that receives f8.mes.
extern unsigned char TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage_Variant2[];

void LoadTwoFontArchivesUnderLoaderLock(void* p);
void Graphics_ResetCharacterResourceHeader(char* p);
int Graphics_GetCharacterResourceByteSize(char* p);
void DisplayContext_InitializeDefaults(char* p);
void DisplayContext_IgnoreAllocatorInitialization(void* context, SafeAllocator* allocator);
void DisplayContext_SetGlobalInstance(unsigned int v);
void TextLookup_RelocateKeyAndValueTables(int* p);
}

// Shared text resource table at 0x02107800. Roles come from the accepted readers named
// below; offset-qualified names are buffers whose roles remain unresolved.
struct TextSharedResources
{
    char* scratchBuffer;   // +0x00: 0xF99 bytes; Text_GetSharedResourceScratchBuffer.
    char* characterData;   // +0x04: windata3.bncg tiles; TextLayout_GetThirtyTwoByteFontEntry.
    char* workBuffer08;    // +0x08: 0x280 bytes.
    char* workBuffer0C;    // +0x0C: 0x960 bytes.
    char* typeEightTable;  // +0x10: relocated f8.mes; TextLookup_ReadGlobalResourceForTypeEight.
    char* workBuffer14;    // +0x14: 0x960 bytes.
    char* workBuffer18;    // +0x18: 0x960 bytes.
    char* context;         // +0x1C: 0x1E2C-byte text context; TextContext_GetSharedInstance.
    unsigned int word20;   // +0x20: not accessed here; the original map also labels 0x02107820.
    char* workBuffer24;    // +0x24: 0x960 bytes.
    char* workBuffer28;    // +0x28: 0x280 bytes.
};

static inline TextSharedResources& SharedResources()
{
    return *(TextSharedResources*)TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage;
}

static inline SafeAllocator& ContextAllocator()
{
    return *(SafeAllocator*)TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage;
}

// Original: arm9/main @ 0x020421C4; symbol: func_020421c4; size: 0x2E8.
// Allocates the shared text context and work buffers, loads both font archives and the
// windata3.bncg character data, decompresses f8.mes from font_lv5.gp2 into ITCM, creates
// the display context, relocates the f8.mes key/value tables and links the work buffers
// into the text context.
extern "C" void Text_InitializeSharedContextAndResources(SafeAllocator* allocator)
{
    GPCReadPair archive;
    char characterHeader[12];
    unsigned int fileLength, length;

    ContextAllocator().CreateTypeA(allocator->Allocate(0x400), 0x400);
    SharedResources().context = (char*)allocator->Allocate(0x1E2C);
    SharedResources().scratchBuffer = (char*)allocator->Allocate(0xF99);
    *(char**)(SharedResources().context + 0x34) = (char*)allocator->Allocate(0xE0);
    SharedResources().workBuffer14 = (char*)allocator->Allocate(0x960);
    SharedResources().workBuffer08 = (char*)allocator->Allocate(0x280);
    SharedResources().workBuffer28 = (char*)allocator->Allocate(0x280);
    SharedResources().workBuffer24 = (char*)allocator->Allocate(0x960);
    SharedResources().workBuffer18 = (char*)allocator->Allocate(0x960);
    SharedResources().workBuffer0C = (char*)allocator->Allocate(0x960);
    LoadTwoFontArchivesUnderLoaderLock(allocator);

    BackgroundLoader::AddLockGlobal();

    // windata3.bncg: a 12-byte character header, with tile data from +0x10.
    fileLength = 0;
    void* file = LoadFileIntoMemory(Text_InitializeSharedContextAndResources_TextDataAniWindata3Bncg,
        Main_UnknownRoleZeroInitializedStorage_Variant6, &fileLength);
    Graphics_ResetCharacterResourceHeader(characterHeader);
    if (file)
        memcpy(characterHeader, file, 12);
    unsigned int characterBytes = Graphics_GetCharacterResourceByteSize(characterHeader);
    SharedResources().characterData = (char*)allocator->Allocate(characterBytes);
    unsigned char* loaded = Main_UnknownRoleZeroInitializedStorage_Variant6;
    memcpy(SharedResources().characterData, loaded + 0x10, characterBytes);

    // f8.mes is decompressed after the archive's file table in the scratch arena, then
    // copied to the ITCM table storage. The pair initialization is the inline form of
    // GPC_InitializeReadPairPointerAndMachine (main 0x02079A3C).
    unsigned int tableOffset = 0;
    unsigned char* scratch = Main_UnknownRoleZeroInitializedStorage_Variant6;
    length = 0;
    unsigned int capacity = 0x30000;
    GPCReadPair* initializing = &archive;
    ZeroInitGPCPointer(&initializing->pGPCFile);
    initializing->ZeroInitializeMachine();
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&archive.pGPCFile, archive.machine,
            Text_InitializeSharedContextAndResources_TextDataPackLv5FontLv5Gp2,
            scratch, length, capacity, false, NULL))
    {
        unsigned int fileTableLength = length;
        DecompressFileFromGPCByName(archive.pGPCFile, archive.machine, scratch + fileTableLength,
            length, capacity - fileTableLength, Text_InitializeSharedContextAndResources_TextF8Mes);
        unsigned int alignedLength = (length + 3) & ~3U;
        archive.Reset();
        // The original adds the zero table offset three times before the aligned length.
        length = tableOffset + (tableOffset + (tableOffset + alignedLength));
        memcpy(TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage_Variant2,
            scratch + fileTableLength, length);
    }

    BackgroundLoader::RemoveLockGlobal();

    ContextAllocator().Reset();
    char* context = SharedResources().context;
    *(SafeAllocator**)(context + 0x2D4) = &ContextAllocator();

    char* displayContext = (char*)allocator->Allocate(0x68);
    DisplayContext_InitializeDefaults(displayContext);
    DisplayContext_IgnoreAllocatorInitialization(displayContext, allocator);
    DisplayContext_SetGlobalInstance((unsigned int)displayContext);

    TextLookup_RelocateKeyAndValueTables(
        (int*)(TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage_Variant2 + tableOffset));
    char* table = (char*)TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage_Variant2;
    table += tableOffset;
    if (table)
        SharedResources().typeEightTable = table;

    *(char**)(SharedResources().context + 0x48) = SharedResources().workBuffer14;
    *(char**)(SharedResources().context + 0x4C) = SharedResources().workBuffer08;
    *(char**)(SharedResources().context + 0x50) = SharedResources().workBuffer28;
    *(char**)(SharedResources().context + 0x5C) = SharedResources().workBuffer24;
    *(char**)(SharedResources().context + 0x60) = SharedResources().workBuffer18;
    *(char**)(SharedResources().context + 0x64) = SharedResources().workBuffer0C;

    archive.Reset();
    ZeroDestroyGPCPointer(&archive.pGPCFile);
}
