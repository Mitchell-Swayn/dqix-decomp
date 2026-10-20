#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C"
{
    void* Network_GetConnectionManager();
    void* GameState_GetIndexList(GameState*);
    bool LinkedQueue_IsEmpty(void*);
    bool GameResources_IsSelectedScreenBrightnessNeutral(GameResources*, int);
    void FieldTreasureMap_InitializeReceiveCommand(void*, int);
    void Grotto_InitializeMapMetadataAndExportNamedDetails(void*, int, int, int, int);
    void LinkedQueue_AppendAndMarkActive(void*, void*);
    void ZoneTransition_InitializeSceneResetRequest(void*);
    void Zone3D_ApplySavedFeatureVisibility(int);
    bool Network_IsSessionActive(void*);
    bool GameState_TestAllListedObjectLinkedFlags(void*);
    void FieldRecovery_QueuePromptIfIdle(GameResources*, int);
}

// Original: arm9/main @ 0x0201BDAC; symbol: _ZN6Zone3D25ProcessTransitionRequestsEv; size: 0x18C.
void Zone3D::ProcessTransitionRequests()
{
    GameState* game = GameState::GetInstance();
    GameResources* resources = GameResources_GetInstance();
    void* controller = resources->unknown_ptr_array_36fc[0];
    void* context = Network_GetConnectionManager();
    void* gameContext = GameState_GetIndexList(game);
    if (!LinkedQueue_IsEmpty(controller)) return;
    if (!GameResources_IsSelectedScreenBrightnessNeutral(resources, 0)) return;
    if (!GameResources_IsSelectedScreenBrightnessNeutral(resources, 1)) return;
    // Requests have priority in bit order and only their own bit is consumed.
    if (transitionRequests_ & 1)
    {
        game->GetGrottoStruct()->unknown_9 = 2;
        void* target = resources->unknown_ptr_array_3afc[27];
        FieldTreasureMap_InitializeReceiveCommand(target, 0);
        Grotto_InitializeMapMetadataAndExportNamedDetails(target, transitionParameter1_, transitionParameter2_, transitionParameter3_, 0);
        LinkedQueue_AppendAndMarkActive(controller, target);
        transitionRequests_ &= ~1;
        return;
    }
    if (transitionRequests_ & 2)
    {
        void* target = resources->unknown_ptr_array_3afc[47];
        ZoneTransition_InitializeSceneResetRequest(target);
        LinkedQueue_AppendAndMarkActive(controller, target);
        transitionRequests_ &= ~2;
        return;
    }
    if (transitionRequests_ & 4)
    {
        Zone3D_ApplySavedFeatureVisibility(0);
        transitionRequests_ &= ~4;
        return;
    }
    if (Network_IsSessionActive(context))
    {
        if (GameState_TestAllListedObjectLinkedFlags(gameContext) || (transitionRequests_ & 8))
            FieldRecovery_QueuePromptIfIdle(resources, 1);
    }
    transitionRequests_ = 0;
}
