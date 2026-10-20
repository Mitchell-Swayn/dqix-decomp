#include "World/WorldPlacementSource.h"
#include "World/WorldPlacementPaths.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern "C" int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned int);

// Original: arm9/main @ 0x0208E520; symbol: _ZN20WorldPlacementSource10LoadForMapEPKc; size: 0x258.
void WorldPlacementSource::LoadForMap(const char* name)
{
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return;
    BackgroundLoader::AddLockGlobal();
    unsigned int size = 0;
    if (!RuntimeMemory_CompareByteRanges(name, gWorldPlacementPaths.specialMap, 6) &&
        RuntimeMemory_CompareByteRanges(name, mapPrefix, 3))
    {
        if (LoadFileIntoMemory(gWorldPlacementPaths.specialFile, Main_UnknownRoleZeroInitializedStorage_Variant6, &size))
        {
            ClearPlacements();
            Script script;
            script.Initialize();
            script.SetOpcodeLookup(gSpecialPlacementOpcodes);
            script.Load(Main_UnknownRoleZeroInitializedStorage_Variant6, size);
            script.Execute();
            strncpy(mapPrefix, name, 3);
        }
    }
    if (name[0] != 'F')
    {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (!RuntimeMemory_CompareByteRanges(name, mapPrefix, 3))
    {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    char prefix[4] = {0};
    strncpy(prefix, name, 3);
    char path[64] = {0};
    sprintf(path, gWorldPlacementPaths.mapFile, prefix);
    if (LoadFileIntoMemory(gWorldPlacementPaths.archive, Main_UnknownRoleZeroInitializedStorage_Variant6, &size))
    {
        unsigned int length;
        const void* file;
        if (!unknownA)
        {
            if (GetFileInNarc(Main_UnknownRoleZeroInitializedStorage_Variant6, gWorldPlacementPaths.variants, &file, &length, 0))
            {
                Script script;
                script.Initialize();
                script.SetOpcodeLookup(gFieldPlacementOpcodes);
                script.Load(file, length);
                script.Execute();
                unknownA = 1;
            }
        }
        ClearPlacements();
        if (GetFileInNarc(Main_UnknownRoleZeroInitializedStorage_Variant6, path, &file, &length, 0))
        {
            Script script;
            script.Initialize();
            script.SetOpcodeLookup(gFieldPlacementOpcodes);
            script.Load(file, length);
            script.Execute();
        }
        strcpy(mapPrefix, prefix);
    }
    BackgroundLoader::RemoveLockGlobal();
}

