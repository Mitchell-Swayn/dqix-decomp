#include "World/Zone3D.h"
#include "World/Zone3DPaths.h"
#include "World/MapArchive.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileIO.h"

extern "C" void func_0204bf30(void*);
extern "C" void func_0204bf44(void*, SafeAllocator*, const void*, unsigned int);

bool Zone3D::LoadBMDJCollision(Zone3D_BMDJStruct::ObjectEntry* entry, Zone3D_BMDJStruct::StructSizeC* definition)
{
    SafeAllocator* allocator = pAllocator_68_;
    char path[80];
    BuildArcMemberPath(definition->name, gZone3DPaths.collisionExtension, path);
    const void* raw = GetFileFromNARCInMemory(path);
    if (raw)
    {
        entry->unknown_4 = allocator->Allocate(0x4c);
        if (!entry->unknown_4) return false;
        unsigned int length;
        void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*allocator, raw, length);
        if (!decompressed) return false;
        func_0204bf30(entry->unknown_4);
        func_0204bf44(entry->unknown_4, allocator, decompressed, length);
    }
    entry->id = 1;
    return true;
}
