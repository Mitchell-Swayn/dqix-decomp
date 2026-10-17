#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "System/Memory.h"

extern unsigned char data_02114e20[];
extern unsigned char data_0211e33c[];
extern unsigned char data_020f290c[];
extern unsigned char data_020f2925[];
extern unsigned char data_020f2936[];

extern "C" void* AllocatorUnion_AllocateFourByteAligned(const void*, unsigned int);
extern "C" void* ResourceFile_FindNamedPayloadAndSize(void*, const char*, unsigned int*);
extern "C" int ParseRAHCResourceBlock(void*, void**);
extern "C" int ResourceFile_FindAndRelocateTTLPChunk(void*, void**);
extern "C" void DisableInterruptsAndHaltForever();

// Original: arm9/main @ 0x020DB0F0; symbol: func_020db0f0; size: 0x138.
extern "C" void Filesystem_LoadArchiveUsing768ByteTemporaryAllocator(SafeAllocator* self, unsigned int, unsigned int, void*)
{
    void* buffer = AllocatorUnion_AllocateFourByteAligned(data_02114e20, 0x300);
    self->CreateTypeA(buffer, 0x300);
    self->Reset();
    BackgroundLoader::AddLockGlobal();

    void* archive = data_0211e33c;
    unsigned int loadedSize = 0;
    LoadFileIntoMemory((const char*)data_020f290c, archive, &loadedSize);
    unsigned int firstSize = 0;
    unsigned int secondSize = 0;
    void* firstFile = ResourceFile_FindNamedPayloadAndSize(archive, (const char*)data_020f2925, &firstSize);
    void* secondFile = ResourceFile_FindNamedPayloadAndSize(archive, (const char*)data_020f2936, &secondSize);

    void* firstRecord = 0;
    if (ParseRAHCResourceBlock(firstFile, &firstRecord) == 0) {
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
