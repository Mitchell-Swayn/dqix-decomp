#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C"
{
    void* Object_GetGlobalConnectionState();
    void* GameState_GetIndexList(GameState*);
    bool IsFirstSignedWordZero(void*);
    bool IsSelectedFloatFieldZeroAfterIntegerConversion(GameResources*, int);
    void func_ov017_021a9bc4(void*, int);
    void func_ov017_021a9a9c(void*, int, int, int, int);
    void AppendLinkedNodeAndMarkActive(void*, void*);
    void InitializeRecordKind48(void*);
    void ApplyZoneModeAndRecordedFlagStates(int);
    bool IsFirstWordNonzero(void*);
    bool GameState_TestAllListedObjectLinkedFlags(void*);
    void QueueTransitionRequestIfUninitialized(GameResources*, int);
}

// Original: arm9/main @ 0x0201BDAC; symbol: _ZN6Zone3D25ProcessTransitionRequestsEv; size: 0x18C.
void Zone3D::ProcessTransitionRequests()
{
    GameState* game = GameState::GetInstance();
    GameResources* resources = GameResources_GetInstance();
    void* controller = resources->unknown_ptr_array_36fc[0];
    void* context = Object_GetGlobalConnectionState();
    void* gameContext = GameState_GetIndexList(game);
    if (!IsFirstSignedWordZero(controller)) return;
    if (!IsSelectedFloatFieldZeroAfterIntegerConversion(resources, 0)) return;
    if (!IsSelectedFloatFieldZeroAfterIntegerConversion(resources, 1)) return;
    // Requests have priority in bit order and only their own bit is consumed.
    if (transitionRequests_ & 1)
    {
        game->GetGrottoStruct()->unknown_9 = 2;
        void* target = resources->unknown_ptr_array_3afc[27];
        func_ov017_021a9bc4(target, 0);
        func_ov017_021a9a9c(target, transitionParameter1_, transitionParameter2_, transitionParameter3_, 0);
        AppendLinkedNodeAndMarkActive(controller, target);
        transitionRequests_ &= ~1;
        return;
    }
    if (transitionRequests_ & 2)
    {
        void* target = resources->unknown_ptr_array_3afc[47];
        InitializeRecordKind48(target);
        AppendLinkedNodeAndMarkActive(controller, target);
        transitionRequests_ &= ~2;
        return;
    }
    if (transitionRequests_ & 4)
    {
        ApplyZoneModeAndRecordedFlagStates(0);
        transitionRequests_ &= ~4;
        return;
    }
    if (IsFirstWordNonzero(context))
    {
        if (GameState_TestAllListedObjectLinkedFlags(gameContext) || (transitionRequests_ & 8))
            QueueTransitionRequestIfUninitialized(resources, 1);
    }
    transitionRequests_ = 0;
}
