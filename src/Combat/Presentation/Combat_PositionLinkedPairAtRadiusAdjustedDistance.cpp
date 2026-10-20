#include <globaldefs.h>
#include <Graphics/Vector.h>
#include <System/Matrix.h>
ARM
#pragma optimization_level 4
typedef Vector3fix Vec;
struct Object { char pad[68]; Vector3fix position; };
struct StateMode { unsigned char mode:7; unsigned char face:1; };
class GameState;
extern "C" {
unsigned BattleScene_GetActiveInstance();
void* _ZN9GameState11GetInstanceEv();
void* Combat_GetCommandActorSnapshot(void*, int);
void* Combat_GetIndexedActionTarget(void*, int);
void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
int _ZNK8Object3D9GetRadiusEv(void*);
Vec* _ZN8Vector3iaSERKS_(Vec*, const Vec*);
int _Z25Vector3fixSquaredDistancePK8Vector3iS1_(const Vec*, const Vec*);

void Vector3fix_Normalize(const Vec*, Vec*);
void Combat_SetPlacementVectorComponents(Vec*, int, int, int);
void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vec*, int, Vec*);
void Combat_ResetSelectedCombatantComponentStates(char*);
void BattleScene_RestoreCombatantHomeTransforms(unsigned char*);
void Graphics_ApplySelectedAndIndexedCombatantTransforms(unsigned char*);
void BattleScene_RestoreCombatantHomeTransforms(unsigned char*);
void Graphics_ApplySelectedAndIndexedCombatantTransforms(unsigned char*);
int MiniMedalMenu_BranchOnCarriedMedalAvailability(void*);
void BattleScene_CenterSelectedCombatantFormation(void*, void*, unsigned char);
void Object3D_FaceTargetPosition(Object*, const Vector3fix*);
}
// Original: arm9/ov025 @ 0x021E6CF4; symbol: func_ov025_021e6cf4; size: 0x204.
// Computes opposing positions for a linked combatant pair and optionally turns each toward the other.
extern "C" int Combat_PositionLinkedPairAtRadiusAdjustedDistance(unsigned char* self, void* target) {
    unsigned char* control = (unsigned char*)BattleScene_GetActiveInstance();
    if ((((StateMode*)(self + 8))->mode) == 0) {
        BattleScene_RestoreCombatantHomeTransforms((unsigned char*)control);
        goto done;
    }
    if ((((StateMode*)(self + 8))->mode) == 1) {
        Graphics_ApplySelectedAndIndexedCombatantTransforms((unsigned char*)control);
        goto done;
    }
    if ((((StateMode*)(self + 8))->mode) == 2) {
        void* state = _ZN9GameState11GetInstanceEv();
        unsigned char* primary = (unsigned char*)Combat_GetCommandActorSnapshot(target, 0);
        unsigned char* secondary = (unsigned char*)Combat_GetIndexedActionTarget(target, 0);
        if (!primary || !secondary) return 1;
        void* first = _ZN9GameState19GetCombatantByIndexEi(state, *(unsigned short*)(primary + 0x20));
        void* second = _ZN9GameState19GetCombatantByIndexEi(state, *(short*)(secondary + 0xe));
        if (!first || !second) return 1;
        Vec firstPosition, secondPosition, direction, opposite, firstOffset, secondOffset;
        _ZN8Vector3iaSERKS_(&firstPosition, (Vec*)((char*)first + 0x44));
        _ZN8Vector3iaSERKS_(&secondPosition, (Vec*)((char*)second + 0x44));
        firstPosition.y = 0xcc;
        secondPosition.y = 0xcc;
        if (_Z25Vector3fixSquaredDistancePK8Vector3iS1_(&firstPosition, &secondPosition) > 0) {
            Vector3fix_Subtract(&secondPosition, &firstPosition, &direction);
            Vector3fix_Normalize(&direction, &opposite);
        } else {
            Combat_SetPlacementVectorComponents(&direction, 0, 0, 0x1000);
            Combat_SetPlacementVectorComponents(&opposite, 0, 0, 0x1000);
        }
        int firstRadius = (int)_ZNK8Object3D9GetRadiusEv(first);
        int secondRadius = (int)_ZNK8Object3D9GetRadiusEv(second);
        int firstHalf = (int)(firstRadius + ((unsigned)firstRadius >> 31)) >> 1;
        int secondHalf = (int)(secondRadius + ((unsigned)secondRadius >> 31)) >> 1;
        int spacing = 0x6000 + firstHalf + secondHalf;
        int negativeSpacing = -spacing;
        int firstScale = (int)(negativeSpacing + ((unsigned)negativeSpacing >> 31)) >> 1;
        int secondScale = (int)(spacing + ((unsigned)spacing >> 31)) >> 1;
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&opposite, firstScale, &firstOffset);
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&opposite, secondScale, &secondOffset);
        Combat_ResetSelectedCombatantComponentStates((char*)control);
        firstOffset.y = 0xcc;
        secondOffset.y = 0xcc;
        _ZN8Vector3iaSERKS_((Vec*)((char*)first + 0x44), &firstOffset);
        _ZN8Vector3iaSERKS_((Vec*)((char*)second + 0x44), &secondOffset);
        if (((StateMode*)(self + 8))->face) {
            Object3D_FaceTargetPosition((Object*)first, &secondOffset);
            Object3D_FaceTargetPosition((Object*)second, &firstOffset);
        }
    } else if ((((StateMode*)(self + 8))->mode) == 3) {
        Combat_ResetSelectedCombatantComponentStates((char*)control);
        BattleScene_CenterSelectedCombatantFormation(control, target, self[9]);
    }
done:
    return 1;
}
