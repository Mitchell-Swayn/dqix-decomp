#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C"
{
    int GameState_ReadByteAtOffset4(GameState*);
    bool GameState_GetPendingFieldReloadMode(GameState*);
    int GameState_GetStartupDispatchMode(GameState*);
}

// Numeric mode tests and the unidentified state fields preserve the original
// initialization conditions; their gameplay purposes remain unresolved.
// Original: arm9/main @ 0x020134E0; symbol: _ZN6Zone3D15InitializeStateEv; size: 0x238.
void Zone3D::InitializeState()
{
    GameState* game = GameState::GetInstance();
    currentZoneID_ = 0;
    previousZoneID_ = 0;
    unknown_4_ = 0;
    unknown_424_ = 0;
    pUnknownStruct_8_ = NULL;
    pAllocator_4c_ = NULL;
    pAllocator_68_ = NULL;
    unknown_ptr_50_ = NULL;
    unknown_476_ = 0;
    numChests_ = 0;
    unknown_82c_ = 0;
    unk_830[0] = 0;
    unknown_428_ = 1;
    textureImageMemory_ = 0;
    texturePaletteMemory_ = 0;
    unknown_42c_ = 0;
    firstBMDJStruct_41c_ = NULL;
    firstModel_418_ = NULL;
    unknown_478_ = NULL;
    unknown_47c_ = NULL;
    unknown_834_ = 0;
    isInMainGrottoFloor_23b8_ = false;
    unknown_23b9_ = 0;
    grottoTileMapData_420_ = NULL;
    unk_23bc[0] = 0;
    unknown_276c_ = -1;
    unknown_2770_ = 0;
    unk_830[1] = 0;
    unk_830[2] = 0;
    unk_830[3] = 0;
    unk_281f = 0;
    unknown_2820_ = 0;
    unknown_27d6_ = 0;
    copyOfCurrentGrottoFloor_23bb_ = -1;
    bFeatures_.Reset();
    atmosphericEffects_.Reset();
    lighting_.Initialize();
    internalAllocator_.ResetAllocatorPointer();
    transitionAllocator_.ResetAllocatorPointer();
    models_498_[0].Clear();
    models_498_[1].Clear();
    state_2724_.Reset();
    unknown_27c4_ = 0;
    unknown_27b8_.x = 0;
    unknown_27b8_.y = 0xa000;
    unknown_27b8_.z = 0;
    unknown_820_ = 0;
    ResetZoneFragmentParts(fragmentParts_);
    memset(unk_27dc, 0, 0x40);
    unknown_281c_ = 0;
    transitionRequests_ = 0;
    transitionParameter1_ = 1;
    transitionParameter2_ = 0;
    transitionParameter3_ = 0;
    unknown_274c_ = 1;
    unknown_2750_ = 1;
    if (GameState_ReadByteAtOffset4(game) != 5)
    {
        unknown_27d8_ = 0;
        unknown_27da_ = 0;
    }
    unknown_281d_ = 0;
    unknown_281e_ = 0;
    if (GameState_GetPendingFieldReloadMode(game)) return;
    if (GameState_GetStartupDispatchMode(game) == 5 || GameState_ReadByteAtOffset4(game) == 4 || GameState_ReadByteAtOffset4(game) == 2)
    {
        state_840_.Reset();
        unknown_27b4_ = 2;
        unknown_27b6_ = 0;
        unknown_2784_ = 0;
        unknown_2786_ = 0x76c;
        unknown_2788_ = 0;
        unknown_2780_ = 0;
        unknown_2794_ = 0x50;
        unknown_27d0_ = 0;
        unknown_2774_.x = 0x19000;
        unknown_2774_.y = 0x199;
        unknown_2774_.z = 0x38ccc;
    }
}

// Original: arm9/main @ 0x02013718; symbol: _ZN6Zone3D19InitializeResourcesEP13SafeAllocatorPv; size: 0x38.
void Zone3D::InitializeResources(SafeAllocator* allocator, void* context)
{
    InitializeState();
    pAllocator_4c_ = allocator;
    unknown_ptr_50_ = context;
    textureImageMemory_ = 0;
    texturePaletteMemory_ = 0;
    unknown_474_ = 0;
    unknown_82c_ = 0;
}
