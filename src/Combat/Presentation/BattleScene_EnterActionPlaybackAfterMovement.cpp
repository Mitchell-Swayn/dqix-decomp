#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct EnterPlaybackActor { unsigned char prefix[0x20]; unsigned short actorId; unsigned char unknown22[0xe]; EnterPlaybackActor* next; };
struct EnterPlaybackTarget { unsigned char prefix[0xe]; short actorId; };
struct EnterPlaybackCommand { unsigned char prefix[0x10]; EnterPlaybackActor* actors; };
extern "C" {
char* BattleScene_ResolveCurrentActionRecord(char*);
int Overlay_TestResolvedRecordTransformState(char*);
void* Combat_GetIndexedActionTarget(void*, int);
void CombatantMotion_DisableSidestep(char*);
bool GameObject_HasBattleMotionFlag200(unsigned int**);
void CombatantMotion_SetDeferredTurnTargetIndex(int, int);
void Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(Object3D*, int, int);
// Original data: arm9/ov025 @ 0x021EF404; symbol: data_ov025_021ef404.
extern unsigned BattleSceneStartCurrentAction_UnknownRoleInitializedBytes[];
// Original data: arm9/ov025 @ 0x021EF974; symbol: data_ov025_021ef974.
extern unsigned char BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage[];
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021DC220; symbol: func_ov025_021dc220; size: 0x104.
// Enters action playback, disabling sidesteps and optionally facing actors toward the first target.
extern "C" void BattleScene_EnterActionPlaybackAfterMovement(void* scene)
{
    unsigned char* self = (unsigned char*)scene;
    GameState* game = GameState::GetInstance();
    EnterPlaybackCommand* command = (EnterPlaybackCommand*)BattleScene_ResolveCurrentActionRecord((char*)self);
    int targetId = -1;
    if (Overlay_TestResolvedRecordTransformState((char*)self)) {
        BattleSceneStartCurrentAction_UnknownRoleInitializedBytes[1] = 1;
        *(int*)(self + 0xeac) = 6;
        EnterPlaybackTarget* target = (EnterPlaybackTarget*)Combat_GetIndexedActionTarget(command, 0);
        if (target) targetId = target->actorId;
    } else *(int*)(self + 0xeac) = 3;
    if (!command) return;
    EnterPlaybackActor* actor = command->actors;
    while (actor) {
        GameObject* object = game->GetCombatantByIndex(actor->actorId);
        if (object) {
            CombatantMotion_DisableSidestep((char*)object);
            if (targetId >= 0) {
                int turn = 1;
                if (GameObject_HasBattleMotionFlag200((unsigned int**)object) || !self[0xe78]) turn = 0;
                if (turn) {
                    if (BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage[0]) CombatantMotion_SetDeferredTurnTargetIndex((int)object, targetId);
                    else Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation((Object3D*)object, targetId, 1);
                }
            }
        }
        actor = actor->next;
    }
}
#pragma force_active reset
