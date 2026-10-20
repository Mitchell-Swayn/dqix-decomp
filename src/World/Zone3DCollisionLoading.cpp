#include "World/Zone3D.h"
#include "World/Zone3DPaths.h"
#include "World/MapArchive.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileIO.h"

extern "C" void ZoneCollision_ResetResource(void*);
extern "C" void ZoneCollision_InitializePackedResource(void*, SafeAllocator*, const void*, unsigned int);

// Original: arm9/main @ 0x02015134; symbol: _ZN6Zone3D17LoadBMDJCollisionEPN17Zone3D_BMDJStruct11ObjectEntryEPNS0_11StructSizeCE; size: 0x98.
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
        ZoneCollision_ResetResource(entry->unknown_4);
        ZoneCollision_InitializePackedResource(entry->unknown_4, allocator, decompressed, length);
    }
    entry->kind = 1;
    return true;
}
