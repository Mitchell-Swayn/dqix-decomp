#include "World/WorldObjectInstanceList.h"
#include "World/WorldPlacementSource.h"
#include "World/WorldPlacementPersistentData.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern "C" {
    void func_020120d4(GameState*, unsigned char);
    void func_0208ec04(WorldObjectInstanceList*);
    int rand();
}

extern "C" void func_0208ea10(WorldObjectInstanceList* list)
{
    GameState* game = GameState::GetInstance();
    if (*((unsigned char*)game + 0x5cda) == 8)
    {
        list->Reset();
        func_020120d4(game, (unsigned char)(rand() % 8));
    }
    else
    {
        func_0208ec04(list);
        return;
    }
    BackgroundLoader::AddLockGlobal();
    char path[64] = {0};
    unsigned int size = 0;
    if (LoadFileIntoMemory(data_020f1330, data_0211e33c, &size))
    {
        unsigned int length;
        const void* file;
        if (GetFileInNarc(data_0211e33c, data_020f134a, &file, &length, 0))
        {
            Script script;
            script.Initialize();
            script.SetOpcodeLookup(gWorldPlacementPersistentData.opcodes);
            script.Load(file, length);
            script.Execute();
            WorldPlacementSource::GetInstance()->unknownA = 1;
        }
        for (int i = 1; i <= 63; ++i)
        {
            sprintf(path, data_020f1356, i);
            size = 0;
            if (GetFileInNarc(data_0211e33c, path, &file, &length, 0))
            {
                Script script;
                script.Initialize();
                script.SetOpcodeLookup(gWorldPlacementPersistentData.opcodes);
                script.Load(file, length);
                script.Execute();
            }
        }
        for (int i = 0; i < 2; ++i)
        {
            WorldPlacementSource::PersistentState* state =
                &((WorldPlacementSource::PersistentState*)((char*)game + 0x5cdc))[i + 98];
            state->available = 1;
            state->unknown25 = 2;
            state->count = 1;
            state->unknown13 = 1;
            state->unknown29 = 1;
            state->unknown0 = 0;
            state->flags = 0;
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
