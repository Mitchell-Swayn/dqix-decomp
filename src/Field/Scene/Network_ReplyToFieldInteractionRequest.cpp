#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" {
void* Network_GetConnectionManager();
int Network_GetLocalMemberId(void*);
GameResources* GameResources_GetInstance();
void FieldNetwork_QueueMemberByteResponse(unsigned, int, int);
}
struct FieldInteractionState { char unknown_0000[0x4447]; signed char interactionIndex; };
#pragma force_active on
// Original: arm9/ov017 @ 0x0219949C; symbol: func_ov017_0219949c; size: 0xDC.
// Rejects requests from another owner or interaction index, then replies by member order.
extern "C" void Network_ReplyToFieldInteractionRequest(FieldInteractionState* field, int objectIndex, int destination, unsigned member, signed char interactionIndex) {
    void* network = Network_GetConnectionManager();
    if (destination != Network_GetLocalMemberId(network) && destination != 4) return;
    GameState* game = GameState::GetInstance();
    GameObject* object = game->GetGameObjectByIndex(objectIndex);
    GameObject* leader = game->GetUnknownGameObject();
    int owner = object->obj3D_.GetField06();
    if (owner != leader->obj3D_.GetField06()) {
        FieldNetwork_QueueMemberByteResponse(member, 1, 1);
        return;
    }
    if (interactionIndex != field->interactionIndex) {
        GameResources_GetInstance();
        FieldNetwork_QueueMemberByteResponse(member, 1, 1);
        return;
    }
    if (member < (unsigned char)Network_GetLocalMemberId(network)) {
        FieldNetwork_QueueMemberByteResponse(member, 1, 1);
        return;
    }
    FieldNetwork_QueueMemberByteResponse(member, 1, 0);
}
#pragma force_active off
