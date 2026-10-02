#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C"
{
    void func_02094d00(void*);
    int func_0200fb9c(GameState*);
    bool func_020115a8(GameState*);
    int func_0201201c(GameState*);
    void func_020982b4(void*);
}

// Numeric mode tests and the unidentified state fields preserve the original
// initialization conditions; their gameplay purposes remain unresolved.
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
    func_02094d00(unknown_struct_2724_);
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
    if (func_0200fb9c(game) != 5)
    {
        unknown_27d8_ = 0;
        unknown_27da_ = 0;
    }
    unknown_281d_ = 0;
    unknown_281e_ = 0;
    if (func_020115a8(game)) return;
    if (func_0201201c(game) == 5 || func_0200fb9c(game) == 4 || func_0200fb9c(game) == 2)
    {
        func_020982b4(unk_840);
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
