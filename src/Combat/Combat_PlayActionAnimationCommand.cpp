#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/LightingManager.h>
#include <std_library_functions.h>
ARM

typedef unsigned int undefined4;
struct AngleState { char unknown[0x58]; int angle; int sine; int cosine; };
struct Globals { unsigned pad[7]; unsigned flags; };

extern "C" {
extern Globals CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern char Combat_PlayActionAnimationCommand_TextMagic[];
extern char Combat_PlayActionAnimationCommand_TextMagic1[];
extern char Combat_PlayActionAnimationCommand_TextMagicIn[];
extern char Main_UnknownRoleZeroInitializedStorage[];
void* GameState_ReadUnknownB0(GameState* state);
undefined4 Camera_GetObjectFlags(undefined4 *param_1);
undefined4 BoneTrackingCamera_GetSourceObject(int param_1);
void Camera_SetProjectionAngle(AngleState *state, int angle);
void BoneTrackingCamera_UpdateEndpointsAndAttachment(void*);
int Combat_DispatchSelectionProcedure(void* context, void* action, int selector, int* output);
void ResetLinkedMotionFieldsAndRestorePosition(char **p);
void CombatantMotion_DisableSidestep(char* p);
void GameObject_SetMotionStateAndRefreshAnimation(unsigned char *p, unsigned char value);
unsigned BattleScene_GetActiveInstance();
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
}

// Original: arm9/ov025 @ 0x021E2980; symbol: func_ov025_021e2980; size: 0x2b4.
// Sets selected object animations with fallback names and updates lighting, sound, and overlay completion flags.
extern "C" int Combat_PlayActionAnimationCommand(unsigned char* action, unsigned char* record, int unused, void* context)
{
    GameState* game = GameState::GetInstance();
    if (action[14] == 25) {
        void* camera = GameState_ReadUnknownB0(game);
        if (Camera_GetObjectFlags((undefined4*)camera) & 16) {
            undefined4 objectAddress = BoneTrackingCamera_GetSourceObject((int)camera);
            if (objectAddress) {
                Object3D* object = (Object3D*)objectAddress;
                Camera_SetProjectionAngle((AngleState*)camera, 0xf000);
                object->SetAnimationByName(*(char**)(action + 8), *(unsigned short*)(action + 12));
                BoneTrackingCamera_UpdateEndpointsAndAttachment(camera);
                CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags |= 8;
            }
        }
    } else {
        int ids[8];
        int count = Combat_DispatchSelectionProcedure(context, record, action[14], ids);
        if (!count)
            return 1;
        for (int i = 0; i < count; i++) {
            unsigned char* object = (unsigned char*)game->GetGameObjectByIndex(ids[i]);
            if (!object)
                continue;
            if (*(unsigned short*)object & 128) {
                ResetLinkedMotionFieldsAndRestorePosition((char**)object);
                CombatantMotion_DisableSidestep((char*)object);
                if (object[190] != 0 && object[190] != 4 && object[190] != 6)
                    GameObject_SetMotionStateAndRefreshAnimation(object, 0);
            }
            ((Object3D*)object)->SetAnimationPlaybackSpeed(4096, 0);
            ((Object3D*)object)->SkipAnimationTransition();
            if (!((Object3D*)object)->SetAnimationByName(*(char**)(action + 8), *(unsigned short*)(action + 12)) &&
                !strcmp(*(char**)(action + 8), Combat_PlayActionAnimationCommand_TextMagic)) {
                if (!((Object3D*)object)->SetAnimationByName(Combat_PlayActionAnimationCommand_TextMagic1, *(unsigned short*)(action + 12)))
                    ((Object3D*)object)->SetAnimationByName(Combat_PlayActionAnimationCommand_TextMagicIn, *(unsigned short*)(action + 12));
            }
        }
        LightingManager* lighting = LightingManager::GetInstance();
        if (!(action[15] & 2) && *(unsigned short*)record != 1 && *(unsigned short*)record != 2 && *(unsigned short*)record != 219) {
            unsigned char* control = (unsigned char*)BattleScene_GetActiveInstance();
            if (!control[0x6fd4]) {
                lighting->BeginFade(0x999, 300);
                control[0x6fd4] = 1;
            }
        }
        char* name = *(char**)(action + 8);
        if (!strcmp(name, Combat_PlayActionAnimationCommand_TextMagicIn) ||
            !strcmp(name, Combat_PlayActionAnimationCommand_TextMagic) ||
            !strcmp(name, Combat_PlayActionAnimationCommand_TextMagic1)) {
            if (!(action[15] & 1)) {
                if (record[10] & 1)
                    SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 102, 0);
                else
                    SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 100, 0);
            }
            lighting->BeginFade(0x4cc, 1000);
            CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags |= 0x200;
        } else
            CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags |= 1;
    }
    CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.flags |= 4;
    return 1;
}
