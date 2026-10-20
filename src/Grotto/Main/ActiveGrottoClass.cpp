#include "Grotto/Main/ActiveGrottoClass.h"
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "World/ZonePredicates.h"
#include "GameState/GameState.h"
#include <globaldefs.h>

#ifdef jpn
    #define Random_SelectScaledInclusiveIntegerRange func_02031efc

    #define Zone3D_GetMainInstance func_02012dac

    #define TreasureMap_LoadLanguageDataAndOffsets func_020a5498
    #define GameState_FreeTreasureMapLanguageBuffersAndRestoreCache func_020a5698
    #define func_020a3a34 func_020a5770
#endif

extern "C"
{
    // RandRange but it's implemented by double arithmetic
    int Random_SelectScaledInclusiveIntegerRange(int minimum, int maximum);

    // Returns the 'zone struct' (still need to figure out what this contains)
    void* Zone3D_GetMainInstance();

    // Not sure exactly what these do but it involves loading/unloading
    // data/tmap/tdata.gp2
    void TreasureMap_LoadLanguageDataAndOffsets();
    void GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();
}

// USA: func_0209fe68
// JPN: func_02090780
// Original: arm9/main @ 0x0208FE68; symbol: _ZN17ActiveGrottoClass17CalculateFloorMapEiiiP8FloorMap; size: 0x68.
bool ActiveGrottoClass::CalculateFloorMap(int floor, int width, int height, FloorMap* pFloorMap)
{
    if (pFloorMap == NULL)
        pFloorMap = &floorMap_;
    
    pFloorMap->Initialize(width, height);
    pGenerator_->Initialize();
    pGenerator_->pFloorMap = pFloorMap;
    pGenerator_->seed = GetActiveGrottoSeed();
    pGenerator_->Calculate(floor, 0);
    pFloorMap->ComputeAdjacencyData();
    return true;
}

// USA: func_0208fed0
// USA: func_020907e8
// Original: arm9/main @ 0x0208FED0; symbol: _ZN17ActiveGrottoClass27CalculateAndStoreFloorWidthEi; size: 0x8C.
int ActiveGrottoClass::CalculateAndStoreFloorWidth(int floor)
{
    if (floor >= 0 && floor <= 4)
        floorWidth_ = GetMapDimensionFromRange(10, 14, floor);
    else if (floor >= 5 && floor <= 8)
        floorWidth_ = GetMapDimensionFromRange(12, 15, floor);
    else if (floor >= 9 && floor <= 12)
        floorWidth_ = GetMapDimensionFromRange(14, 16, floor);
    else
        floorWidth_ = 16;

    return floorWidth_;
}

// USA: func_0208ff5c
// JPN: func_02090874
// Original: arm9/main @ 0x0208FF5C; symbol: _ZN17ActiveGrottoClass28CalculateAndStoreFloorHeightEi; size: 0x8C.
int ActiveGrottoClass::CalculateAndStoreFloorHeight(int floor)
{
    if (floor >= 0 && floor <= 4)
        floorHeight_ = GetMapDimensionFromRange(10, 14, floor);
    else if (floor >= 5 && floor <= 8)
        floorHeight_ = GetMapDimensionFromRange(12, 15, floor);
    else if (floor >= 9 && floor <= 12)
        floorHeight_ = GetMapDimensionFromRange(14, 16, floor);
    else
        floorHeight_ = 16;

    return floorHeight_;
}

// USA: func_0208ffe8
// JPN: func_02090900
// Original: arm9/main @ 0x0208FFE8; symbol: _ZNK17ActiveGrottoClass19GetFloorMonsterRankEi; size: 0x30.
int ActiveGrottoClass::GetFloorMonsterRank(int floor) const
{
    GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
    if (floor < 1)
        floor = 1;

    return grotto->activeStartingMonsterRank + (floor - 1) / 4;
}

// USA: func_02090018
// JPN: func_02090930
// Original: arm9/main @ 0x02090018; symbol: _ZN17ActiveGrottoClass18RandomizeChestRankEi; size: 0x140.
int ActiveGrottoClass::RandomizeChestRank(int floor)
{
    int monsterRank = GetFloorMonsterRank(floor);
    int chestRank = 0;
    switch (monsterRank)
    {
    case 0:
        break;
    case 1:
        chestRank = Random_SelectScaledInclusiveIntegerRange(1, 2);
        break;
    case 2:
        chestRank = Random_SelectScaledInclusiveIntegerRange(1, 2);
        break;
    case 3:
        chestRank = Random_SelectScaledInclusiveIntegerRange(1, 3);
        break;
    case 4:
        chestRank = Random_SelectScaledInclusiveIntegerRange(1, 4);
        break;
    case 5:
        chestRank = Random_SelectScaledInclusiveIntegerRange(2, 5);
        break;
    case 6:
        chestRank = Random_SelectScaledInclusiveIntegerRange(2, 6);
        break;
    case 7:
        chestRank = Random_SelectScaledInclusiveIntegerRange(3, 7);
        break;
    case 8:
        chestRank = Random_SelectScaledInclusiveIntegerRange(3, 8);
        break;
    case 9:
        chestRank = Random_SelectScaledInclusiveIntegerRange(4, 9);
        break;
    case 10:
        chestRank = Random_SelectScaledInclusiveIntegerRange(5, 9);
        break;
    case 11:
        chestRank = Random_SelectScaledInclusiveIntegerRange(1, 10);
        break;
    case 12:
        chestRank = Random_SelectScaledInclusiveIntegerRange(4, 10);
        break;
    }
    return chestRank;
}

// USA: func_02090158
// JPN: func_02090a70
// Original: arm9/main @ 0x02090158; symbol: _ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv; size: 0x28.
int ActiveGrottoClass::GetActiveGrottoEnviron() const
{
    GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();

    if (grotto->activeMapData.GetMapType() == TreasureMapType_Legacy)
        return 1;
    else
        return grotto->activeEnviron;
}

// USA: func_02090180
// JPN: func_02090a98
// Original: arm9/main @ 0x02090180; symbol: _ZNK17ActiveGrottoClass13GetFloorCountEv; size: 0x7C.
int ActiveGrottoClass::GetFloorCount() const
{
    GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
    void* zone = Zone3D_GetMainInstance();
    if (!IsGrottoZone(*(unsigned short*)zone))
        return 0;

    if (grotto->activeMapData.GetMapType() == TreasureMapType_Legacy)
        return 0;

    if (overallMapData_.discoveryState_ == DiscoveryState_Invalid)
    {
        TreasureMap_LoadLanguageDataAndOffsets();
        DetailedTreasureMapData data;
        ExportDetailedTreasureMapData(&grotto->activeMapData, &data, 1, 0);
        GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();
        return data.regular_.floorCount_;
    }

    return overallMapData_.regular_.floorCount_;
}

// USA: func_020901fc
// JPN: func_02090b14
// Original: arm9/main @ 0x020901FC; symbol: _ZNK17ActiveGrottoClass12GetPopupNameEv; size: 0x6C.
const char* ActiveGrottoClass::GetPopupName() const
{
    GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
    if (overallMapData_.discoveryState_ != DiscoveryState_Invalid)
    {
        if (overallMapData_.mapType_ == TreasureMapType_Legacy)
            return overallMapData_.legacy_.popupName_;
        else
            return overallMapData_.regular_.popupName_;
    }    

    // Returning a temporary, could something go wrong here?
    // Would have to call another function after this which uses the stack.
    TreasureMap_LoadLanguageDataAndOffsets();
    DetailedTreasureMapData data;
    ExportDetailedTreasureMapData(&grotto->activeMapData, &data, 1, 0);
    GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();

    if (data.mapType_ == TreasureMapType_Legacy)
        return data.legacy_.popupName_;
    else
        return data.regular_.popupName_;
}

// USA: func_02090268
// JPN: func_02090b88
// Original: arm9/main @ 0x02090268; symbol: _ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv; size: 0x28.
unsigned short ActiveGrottoClass::GetActiveGrottoSeed() const
{
    GrottoStruct* grottoData = GameState::GetInstance()->GetGrottoStruct();

    if (grottoData->activeMapData.GetMapType() == TreasureMapType_Legacy)
        return 0;

    return grottoData->activeMapData.SeedOrMinTurns;
}

// USA: func_02090290
// JPN: func_02090bb0
// Original: arm9/main @ 0x02090290; symbol: _ZN17ActiveGrottoClass15GetDetailedDataEv; size: 0x4.
DetailedTreasureMapData* ActiveGrottoClass::GetDetailedData()
{
    return &overallMapData_;
}