#include "World/Zone3D.h"
#include "World/Zone3DPaths.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
#include "Graphics/NSBXX/NSBXX.h"
#include "World/ZonePredicates.h"

#if defined(jpn)
#define GameState_GetFieldAddress468 func_020112f4
#define ReadWordFieldAtOffset150 func_02054fe4
#define func_0207a5b8 func_0207b3f0
#define func_0207b9cc func_0207c804
#define SnapshotBlockAndVolatileWordPair func_0207ecd0
#define ReadGlobalAt02108F0C func_0208b2a8
#define func_02094d00 func_02096950
#define Object_FindRecordByKeyInCountedArray func_0209b684
#define func_020de848 func_020e01c4


#endif

extern "C"
{
    void* GameState_GetFieldAddress468(GameState*);

    void* ReadWordFieldAtOffset150(void*);
    void Script_InitializeAndExecuteOwnerContextCode(const char*, SafeAllocator*, const void*, unsigned int);

    // Texture functions
    void* SnapshotBlockAndVolatileWordPair(void*);
    void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
    void Object_InvokeSaveTextureImageVRAMState(void*);

    void* ReadGlobalAt02108F0C();
    Zone3D_StructPtr_8* Object_FindRecordByKeyInCountedArray(void*, unsigned short id);

    void DisableInterruptsAndHaltForever(); // abort() or similar


}


// Original: arm9/main @ 0x0201383C; symbol: _ZN6Zone3D10SwitchZoneEt; size: 0x318.
void Zone3D::SwitchZone(unsigned short newID)
{
    GameState* gameState = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    void* uVar3 = GameState_GetFieldAddress468(gameState);
    (void)GameResources_GetInstance();
    GameObject* iVar4 = gameState->GetUnknownGameObject();

    pAllocator_68_ = pAllocator_4c_;
    pAllocator_68_->Reset();

    SnapshotBlockAndVolatileWordPair(unknown_ptr_50_);
    ResetZoneResources(true);

    previousZoneID_ = currentZoneID_;
    currentZoneID_ = newID;

    textureImageMemory_ = 0;
    texturePaletteMemory_ = 0;
    unknown_424_ = 1;
    firstBMDJStruct_41c_ = 0;
    firstModel_418_ = NULL;
    unknown_476_ = 0;
    numChests_ = 0;
    unknown_82c_ = 0;
    unknown_474_ = 0;
    unknown_82c_ = 0; // why zero it twice?
    unknown_42c_ = 0;

    mapListLoadHandle_ = -1;
    unknown_434_ = -1;
    mapAMBLLoadHandle_ = -1;
    mapAMDJLoadHandle_ = -1;
    atsAMBLLoadHandle_ = -1;

    unknown_478_ = 0;
    unknown_47c_ = 0;
    unknown_834_ = 0;
    unknown_2820_ = 0;

    bFeatures_.Reset();

    mapListInfo_.maybeModelName[0] = 0;
    mapListInfo_.buffer2[0] = 0;
    mapListInfo_.buffer3[0] = 0;
    mapListInfo_.unknown_2a = 0x7fff;
    mapListInfo_.unknown_2c = 0;
    mapListInfo_.unknown_30 = 10;
    mapListInfo_.worldRotation = 0;
    mapListInfo_.unknown_38 = 0;
    mapListInfo_.unknown_3c = 0;

    atmosphericEffects_.Reset();
    lighting_.Reset();
    state_2754_.Reset();

    pUnknownStruct_8_ = Object_FindRecordByKeyInCountedArray(uVar3, newID);
    unknown_4_ = pUnknownStruct_8_->unknown_2_;
    if (pUnknownStruct_8_->unknown_c_low_ == 0)
    {
        GameObject* iVar5 = gameState->GetProtagonist();
        if (iVar5 != NULL)
        {
            void* iVar6 = ReadWordFieldAtOffset150(iVar5);
            if (iVar6 != NULL)
                *(unsigned short*)((int)iVar6 + 0x566) = pUnknownStruct_8_->unknown_0_;
        }
    }

    *(bool*)((int)ReadGlobalAt02108F0C() + 0x9c) = pUnknownStruct_8_->unknown_c_high_ != 0;
    state_2724_.Reset();

    grottoTileMapData_420_ = NULL;

    if (IsMainGrottoFloorZone(previousZoneID_))
    {
        grotto_.floorMap_.Clear();
    }

    if (IsMainGrottoFloorZone(newID))
    {
        isInMainGrottoFloor_23b8_ = true;
        currentGrottoFloor_23ba_ = newID % 20;
        copyOfCurrentGrottoFloor_23bb_ = currentGrottoFloor_23ba_;
        int width = grotto_.CalculateAndStoreFloorWidth(currentGrottoFloor_23ba_);
        int height = grotto_.CalculateAndStoreFloorHeight(currentGrottoFloor_23ba_);

        grottoTileMapData_420_ = (GrottoTileData*)pAllocator_68_->Allocate(sizeof(GrottoTileData) * 256);
        for (int i = 0; i < 256; i++)
        {
            ResetGrottoTileData(&grottoTileMapData_420_[i]);
        }
        grotto_.ClearGenerator(false);
        grotto_.AllocateGenerator(pAllocator_68_, false);
        grotto_.CalculateFloorMap(currentGrottoFloor_23ba_, width, height, NULL);
    }
    else
    {
        if (currentGrottoFloor_23ba_ != -1)
        {
            copyOfCurrentGrottoFloor_23bb_ = currentGrottoFloor_23ba_;
            position_23c0_ = iVar4->obj3D_.position_;
            unknown_23cc_ = *(short*)((int)iVar4 + 0xae);
        }
        isInMainGrottoFloor_23b8_ = false;
        currentGrottoFloor_23ba_ = -1;
    }

    mapListLoadHandle_ = loader->QueueLoadFile(gZone3DPaths.mapList, NULL);
}

// Original: arm9/main @ 0x02013B54; symbol: _ZN8Vector3iaSERKS_; size: 0x1C.
Vector3i& Vector3i::operator=(const Vector3i& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}
