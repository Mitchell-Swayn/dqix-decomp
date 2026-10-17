#include "World/WorldObjectInstanceList.h"
#include "World/WorldPlacementSource.h"
#include "World/WorldPlacementPersistentData.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern "C" {
    void GameState_SetByteField5CDAAndClearPlacementFlag(GameState*, unsigned char);
    void WorldPlacement_ResetFlaggedAvailablePersistentStates(WorldObjectInstanceList*);
    int rand();
}

// Original: arm9/main @ 0x0208EA10; symbol: func_0208ea10; size: 0x1F4.
extern "C" void ResetPlacementListOrLoadPlacementResources(WorldObjectInstanceList* list)
{
    GameState* game = GameState::GetInstance();
    if (game->unknownPlacementByte_5cda_ == 8)
    {
        list->Reset();
        GameState_SetByteField5CDAAndClearPlacementFlag(game, (unsigned char)(rand() % 8));
    }
    else
    {
        WorldPlacement_ResetFlaggedAvailablePersistentStates(list);
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
                &game->placementStates_[i + 98];
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
