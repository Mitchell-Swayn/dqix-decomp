#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <System/Matrix.h>
ARM

struct Vec { int x, y, z; };

extern "C" {
void* Combat_GetCommandActorSnapshot(void* object, int index);
void* Combat_GetIndexedActionTarget(void* object, int index);
void Combat_ResetActionProcedureState(int *p);
void CombatantMotion_DisableSidestep(char* p);
bool GameObject_HasBattleMotionFlag200(unsigned int **p);
bool CombatStatus_HasSleep(unsigned int* p);
void Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(Object3D* p, int id, int turn);
void GameObject_SetMotionStateAndRefreshAnimation(unsigned char *p, unsigned char value);
void ResetLinkedMotionFieldsAndRestorePosition(char **p);
extern int CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage[];
extern char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov025 @ 0x021E6A08; symbol: func_ov025_021e6a08; size: 0x2cc.
// Moves the primary combatant toward the secondary combatant until radius-adjusted separation is reached.
extern "C" int Combat_MoveActionActorTowardTargetUntilInRange(char* action, void* record)
{
    GameState* game = GameState::GetInstance();
    char* primary = (char*)Combat_GetCommandActorSnapshot(record, 0);
    char* secondary = (char*)Combat_GetIndexedActionTarget(record, 0);
    if (!primary || !secondary) {
        Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);
        return 1;
    }
    unsigned char* object = (unsigned char*)game->GetCombatantByIndex(*(unsigned short*)(primary + 32));
    unsigned char* target = (unsigned char*)game->GetCombatantByIndex(*(short*)(secondary + 14));
    if (!object || !target) {
        Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);
        return 1;
    }
    int started = 0;
    if (*(int*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 32) == 0) {
        CombatantMotion_DisableSidestep((char*)object);
        started = 1;
        if (!GameObject_HasBattleMotionFlag200((unsigned int**)target) &&
            !(*(unsigned*)(*(char**)(target + 0x138) + 20) & 8) &&
            !CombatStatus_HasSleep(*(unsigned int**)(target + 0x138)))
            Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(
                (Object3D*)target, *(unsigned short*)(primary + 32), started);
        *(int*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 32) = 1;
    }
    if (*(int*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 32) == 1) {
        Vec position = *(Vec*)(object + 0x44), other = *(Vec*)(target + 0x44), direction, scaled, destination, step, updated;
        int radius = ((Object3D*)object)->GetRadius();
        radius += ((Object3D*)target)->GetRadius();
        int limit = *(int*)(action + 8) + radius / 2;
        int distance = Vector3fix_Distance((const Vector3fix*)&position, (const Vector3fix*)&other);
        if (!distance) {
            Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);
            return 1;
        }
        if (distance < limit) {
            Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);
            return 1;
        }
        Vector3fix_Subtract((const Vector3fix*)&other, (const Vector3fix*)&position, (Vector3fix*)&direction);
        int remaining = distance - limit;
        int scale = fix32_Divide(remaining, distance);
        Vector3fixMultiplyScalar((const Vector3fix*)&direction, scale, (Vector3fix*)&scaled);
        Vector3fix_Add((const Vector3fix*)&position, (const Vector3fix*)&scaled, (Vector3fix*)&destination);
        Vector3fix_Subtract((const Vector3fix*)&destination, (const Vector3fix*)&position, (Vector3fix*)&step);
        scale = fix32_Divide(4096, 16384);
        Vector3fixMultiplyScalar((const Vector3fix*)&step, scale, (Vector3fix*)&step);
        int length = Vector3fix_Length((const Vector3fix*)&step);
        if (length > 0x333) {
            scale = fix32_Divide(0x333, length);
            Vector3fixMultiplyScalar((const Vector3fix*)&step, scale, (Vector3fix*)&step);
        } else if (object[0xc0] != 6) {
            GameObject_SetMotionStateAndRefreshAnimation(object, 0);
        }
        Vector3fix_Add((const Vector3fix*)&position, (const Vector3fix*)&step, (Vector3fix*)&updated);
        *(Vector3i*)(object + 0x44) = *(Vector3i*)&updated;
        if (remaining < 40 || (!started && object[0xc0] == 0)) {
            GameObject_SetMotionStateAndRefreshAnimation(object, 0);
            Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);
            return 1;
        }
    }
    if (started) {
        ResetLinkedMotionFieldsAndRestorePosition((char**)object);
        if (object[0xc0] != 6)
            GameObject_SetMotionStateAndRefreshAnimation(object, 1);
    }
    return 0;
}
