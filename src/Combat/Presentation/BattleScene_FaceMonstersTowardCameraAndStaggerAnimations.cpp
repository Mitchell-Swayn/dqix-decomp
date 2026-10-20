#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Triple { unsigned x, y, z; };
extern "C" {
GameResources* GameState_ReadPResources(GameState*);
int Combat_CollectGroupIndicesByDescriptorFlags(char*, short*, int, unsigned);
GameObject* GameState_FindIndexedObjectWithFlag400(GameState*, int);
void __clear(void*, unsigned);
Triple CombatantMotion_GetHomePosition(char*);
void Object3D_SetNormalizedAngleAndUpdatePosition(char*, int);
void CombatantMotion_SetHomeHeadingFromVector(char*, int*);
void Random_ShuffleFirstHalfByFullArraySwaps(unsigned*, int);
bool GameObject_IsDead(int);
}
#pragma force_active on
// Original: arm9/ov026 @ 0x021DAEC8; symbol: func_ov026_021daec8; size: 0x1C8.
// Faces collected monsters toward the camera depth and optionally staggers their animations.
extern "C" void BattleScene_FaceMonstersTowardCameraAndStaggerAnimations(char* encounter, char* camera, int stagger)
{
    GameState* game = GameState::GetInstance();
    GameState_ReadPResources(game);
    short enemyIds[8];
    int count = Combat_CollectGroupIndicesByDescriptorFlags(encounter, enemyIds, 8, 0);
    int selected = 0;
    Vector3fix cameraPosition = *(Vector3fix*)(camera + 0x240);
    unsigned selectedIds[8];
    int depth = cameraPosition.z;
    for (int i = 0; i < count; ++i) {
        GameObject* object = GameState_FindIndexedObjectWithFlag400(game, enemyIds[i]);
        if (object) {
            Vector3fix facing;
            __clear(&facing, 12);
            facing.z = depth;
            Triple home = CombatantMotion_GetHomePosition((char*)object);
            home.y = 0;
            Vector3fix direction;
            Vector3fix_Subtract(&facing, (Vector3fix*)&home, &direction);
            direction.y = 0;
            Vector3fix_Normalize(&direction, &direction);
            int angle = fix32_Atan2(direction.x, direction.z);
            Object3D_SetNormalizedAngleAndUpdatePosition((char*)object, angle);
            Vector3fix heading;
            __clear(&heading, 12);
            heading.y = angle;
            CombatantMotion_SetHomeHeadingFromVector((char*)object, (int*)&heading);
            selectedIds[selected++] = enemyIds[i];
        }
    }
    if (stagger && *(int*)(encounter + 0x8e20) > 0) {
        Random_ShuffleFirstHalfByFullArraySwaps(selectedIds, selected);
        for (int i = 0; i < selected; ++i) {
            GameObject* object = GameState_FindIndexedObjectWithFlag400(game, selectedIds[i]);
            if (object && !object->obj3D_.IsTransitioningAnimations() && !GameObject_IsDead((int)object)) {
                object->obj3D_.SetNormalizedAnimationTime((0x1000 / selected) * i);
                object->obj3D_.AdvanceAnimations();
            }
        }
    }
}
#pragma force_active reset
