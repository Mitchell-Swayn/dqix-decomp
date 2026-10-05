#include "World/WorldPlacementSource.h"
#include "World/WorldPlacementPaths.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern "C" int func_02001aec(const void*, const void*, unsigned int);

void WorldPlacementSource::LoadForMap(const char* name)
{
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return;
    BackgroundLoader::AddLockGlobal();
    unsigned int size = 0;
    if (!func_02001aec(name, gWorldPlacementPaths.specialMap, 6) &&
        func_02001aec(name, mapPrefix, 3))
    {
        if (LoadFileIntoMemory(gWorldPlacementPaths.specialFile, data_0211e33c, &size))
        {
            ClearPlacements();
            Script script;
            script.Initialize();
            script.SetOpcodeLookup(gSpecialPlacementOpcodes);
            script.Load(data_0211e33c, size);
            script.Execute();
            strncpy(mapPrefix, name, 3);
        }
    }
    if (name[0] != 'F')
    {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (!func_02001aec(name, mapPrefix, 3))
    {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    char prefix[4] = {0};
    strncpy(prefix, name, 3);
    char path[64] = {0};
    sprintf(path, gWorldPlacementPaths.mapFile, prefix);
    if (LoadFileIntoMemory(gWorldPlacementPaths.archive, data_0211e33c, &size))
    {
        unsigned int length;
        const void* file;
        if (!unknownA)
        {
            if (GetFileInNarc(data_0211e33c, gWorldPlacementPaths.variants, &file, &length, 0))
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
        if (GetFileInNarc(data_0211e33c, path, &file, &length, 0))
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

