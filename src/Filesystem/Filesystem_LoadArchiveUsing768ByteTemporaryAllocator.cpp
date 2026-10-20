#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "System/Memory.h"

// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
extern unsigned char Filesystem_LoadArchiveUsing768ByteTemporaryAllocator_PathDataAniObjLoadingPac[];
extern unsigned char Filesystem_LoadArchiveUsing768ByteTemporaryAllocator_TextObjLoadingNCGR[];
extern unsigned char Filesystem_LoadArchiveUsing768ByteTemporaryAllocator_TextObjLoadingNCLR[];

extern "C" void* AllocatorUnion_AllocateFourByteAligned(const void*, unsigned int);
extern "C" void* ResourceFile_FindNamedPayloadAndSize(void*, const char*, unsigned int*);
extern "C" int NNS_G2dGetUnpackedCharacterData(void*, void**);
extern "C" int ResourceFile_FindAndRelocateTTLPChunk(void*, void**);
extern "C" void DisableInterruptsAndHaltForever();

// Original: arm9/main @ 0x020DB0F0; symbol: func_020db0f0; size: 0x138.
extern "C" void Filesystem_LoadArchiveUsing768ByteTemporaryAllocator(SafeAllocator* self, unsigned int, unsigned int, void*)
{
    void* buffer = AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3, 0x300);
    self->CreateTypeA(buffer, 0x300);
    self->Reset();
    BackgroundLoader::AddLockGlobal();

    void* archive = Main_UnknownRoleZeroInitializedStorage_Variant6;
    unsigned int loadedSize = 0;
    LoadFileIntoMemory((const char*)Filesystem_LoadArchiveUsing768ByteTemporaryAllocator_PathDataAniObjLoadingPac, archive, &loadedSize);
    unsigned int firstSize = 0;
    unsigned int secondSize = 0;
    void* firstFile = ResourceFile_FindNamedPayloadAndSize(archive, (const char*)Filesystem_LoadArchiveUsing768ByteTemporaryAllocator_TextObjLoadingNCGR, &firstSize);
    void* secondFile = ResourceFile_FindNamedPayloadAndSize(archive, (const char*)Filesystem_LoadArchiveUsing768ByteTemporaryAllocator_TextObjLoadingNCLR, &secondSize);

    void* firstRecord = 0;
    if (NNS_G2dGetUnpackedCharacterData(firstFile, &firstRecord) == 0) {
        DisableInterruptsAndHaltForever();
    }
    unsigned char* bytes = (unsigned char*)self;
    *(unsigned int*)(bytes + 0x44) = *(unsigned int*)((unsigned char*)firstRecord + 0x10);
    *(void**)(bytes + 0x40) = self->Allocate(*(unsigned int*)(bytes + 0x44));
    MI_CpuCopy8(*(void**)((unsigned char*)firstRecord + 0x14),
                  *(void**)(bytes + 0x40), *(unsigned int*)(bytes + 0x44));

    void* secondRecord = 0;
    if (ResourceFile_FindAndRelocateTTLPChunk(secondFile, &secondRecord) == 0) {
        DisableInterruptsAndHaltForever();
    }
    *(unsigned int*)(bytes + 0x4c) = 0x20;
    *(void**)(bytes + 0x48) = self->Allocate(0x20);
    MI_CpuCopy8(*(void**)((unsigned char*)secondRecord + 0xc),
                  *(void**)(bytes + 0x48), *(unsigned int*)(bytes + 0x4c));
    BackgroundLoader::RemoveLockGlobal();
}
