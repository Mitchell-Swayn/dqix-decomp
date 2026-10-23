#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct CameraWaitActor { unsigned char prefix[0x20]; unsigned short actorId; };
struct CameraWaitTarget { unsigned char prefix[0xe]; short actorId; unsigned char unknown10[0x10]; CameraWaitTarget* next; };
struct CameraWaitCommand { unsigned short actionId; unsigned char prefix[0xe]; CameraWaitActor* actors; CameraWaitTarget* targets; };
struct CameraWaitDefinition { unsigned unknown00; unsigned actionId : 12; unsigned other04 : 20; unsigned unknown08[3]; unsigned other14 : 28; unsigned presentationKind : 4; };
struct ActionTurnObject;
struct OpeningPresentation;
extern "C" {
char* BattleScene_ResolveCurrentActionRecord(char*);
unsigned Combat_IsActionMessageResourcesReady(void*);
void* ActionData_GetGlobalTables();
void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(void*, int);
unsigned BattleCamera_IsActionPairShotSettled(void*);
int Combat_IsDefaultOrSpecialPresentationAction(int);
int Combat_ClassifySpecialEncounterSpecies(unsigned char*);
void World_InitializeMotionBetweenObjects(char*, int, int);
int Combat_CanTurnForActionPresentation(ActionTurnObject*);
bool GameObject_IsFollowingGridPath(void*);
void CombatantMotion_SetDeferredTurnTargetIndex(int, int);
void Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(Object3D*, int, int);
void Combat_QueueOpeningActionMessagesOnce(OpeningPresentation*);
void Combat_PlayActionCategorySoundOnce(unsigned char*, int);
// Original data: arm9/ov025 @ 0x021EF404; symbol: data_ov025_021ef404.
// Mutable initialized action-playback state; word one is the camera-wait latch.
extern unsigned BattleSceneStartCurrentAction_UnknownRoleInitializedBytes[];
// Original data: arm9/ov025 @ 0x021EF974; symbol: data_ov025_021ef974.
// Zero-initialized playback state; byte zero defers turns and halfword two is a timer.
extern unsigned char BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage[];
}
namespace {
#pragma always_inline on
inline int AreCameraWaitTargetsSettled(CameraWaitCommand* command)
{
    GameState* currentGame = GameState::GetInstance();
    CameraWaitTarget* target = command->targets;
    while (target) {
        GameObject* object = currentGame->GetCombatantByIndex(target->actorId);
        if (object && GameObject_IsFollowingGridPath(object)) return 0;
        target = target->next;
    }
    return 1;
}
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021DC324; symbol: func_ov025_021dc324; size: 0x26C.
// Waits for camera settlement and target movement, then advances action playback.
extern "C" void BattleScene_WaitForActionCameraAndTargetMotion(unsigned char* self)
{
    GameState* game = GameState::GetInstance();
    unsigned char* encounter = *(unsigned char**)(self + 0x29c);
    unsigned char* prefix18;
    CameraWaitCommand* command = (CameraWaitCommand*)BattleScene_ResolveCurrentActionRecord((char*)self);
    prefix18 = self + 0x18;
    if (!Combat_IsActionMessageResourcesReady(self + 0x2a8)) return;
    void* actionData = ActionData_GetGlobalTables();
    unsigned char* prefix154 = self + 0x154;
    if (BattleSceneStartCurrentAction_UnknownRoleInitializedBytes[1]) {
        if (!BattleCamera_IsActionPairShotSettled(prefix18 + 0xc00)) return;
        ((Object3D*)(prefix154 + 0x5800))->MakeHidden();
        ((Object3D*)(self + 0x5a00))->MakeHidden();
        int faceTarget = 0;
        CameraWaitDefinition* definition = (CameraWaitDefinition*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)actionData, (short)command->actionId);
        if (Combat_IsDefaultOrSpecialPresentationAction(command->actionId)) faceTarget = 1;
        else if (definition) {
            if (definition->presentationKind == 2) faceTarget = 1;
            if (definition->actionId == 0xae) faceTarget = 1;
        }
        if (faceTarget && command->actors && command->targets) {
            int makeTrail;
            int actorId = command->actors->actorId;
            int targetId = command->targets->actorId;
            makeTrail = 1;
            if (Combat_ClassifySpecialEncounterSpecies(encounter) && actorId == 0) makeTrail = 0;
            if (!prefix18[0xe60]) makeTrail = 0;
            if (makeTrail) World_InitializeMotionBetweenObjects((char*)self + 0x5ab0, actorId, targetId);
            GameObject* target = game->GetCombatantByIndex(targetId);
            if (Combat_CanTurnForActionPresentation((ActionTurnObject*)target)) {
                if (definition->actionId == 0xae && GameObject_IsFollowingGridPath(target)) return;
                if (BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage[0]) CombatantMotion_SetDeferredTurnTargetIndex((int)target, actorId);
                else Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation((Object3D*)target, actorId, 1);
            }
        }
        if (!self[0x5c3a]) *(int*)(self + 0xeac) = 3;
        Combat_QueueOpeningActionMessagesOnce((OpeningPresentation*)(self + 0x2a8));
        BattleSceneStartCurrentAction_UnknownRoleInitializedBytes[1] = 0;
        *(unsigned short*)(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage + 2) = 0;
    } else {
        unsigned delta = game->GetEffectiveDeltaTime();
        unsigned short timer = *(unsigned short*)(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage + 2);
        if (timer < delta) {
            if (AreCameraWaitTargetsSettled(command)) *(int*)(self + 0xeac) = 3;
        } else *(unsigned short*)(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage + 2) = timer - delta;
    }
    if (command->actionId == 0xdb) { *(unsigned short*)(self + 0x876) = 0x2ee; return; }
    Combat_PlayActionCategorySoundOnce(self + 0x2a8, 0);
}
#pragma force_active reset
