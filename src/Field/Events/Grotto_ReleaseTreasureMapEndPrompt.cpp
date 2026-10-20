#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#pragma force_active on
ARM
struct EndPromptResetRecord { unsigned word; unsigned short first,second; };
struct EndPromptState {
    unsigned char unknown_0,complete;
    unsigned char unknown_2[10];
    EndPromptResetRecord resetRecord;
    SafeAllocator allocator;
};
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void Camera_EnableOrbitInput(int);
extern "C" void GameObject_RequestMovementInputEnable(int);
extern "C" void ResetWordAndTwoHalfwordRecord(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x02114E20; symbol: data_02114e20.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021BF398; symbol: func_ov017_021bf398; size: 0x78.
// Restores camera and actor input and releases the treasure-map end prompt's owned resources.
extern "C" void Grotto_ReleaseTreasureMapEndPrompt(void* context)
{
    EndPromptState* prompt=(EndPromptState*)context;
    GameState* game=GameState::GetInstance();
    void* camera=GameState_GetFieldOrbitCamera(game);
    GameObject* actor=game->GetUnknownGameObject();
    Camera_EnableOrbitInput((int)camera);
    GameObject_RequestMovementInputEnable((int)actor);
    SignedAllocatorHeader* allocation=prompt->allocator.GetSignedAllocator();
    if(allocation) {
        prompt->allocator.Reset();
        prompt->allocator.Destroy();
        ResetWordAndTwoHalfwordRecord(&prompt->resetRecord);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
    }
    prompt->complete=1;
}
