#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>
ARM

struct Record {
    unsigned char id, mapped;
    short pad;
    int value;
    char* object;
};
struct Vec { int x, y, z; };

extern "C" {
int BattleScene_CollectMotionPlanningCombatants(void* owner, Record* output);
void ResetLinkedMotionFieldsAndRestorePosition(char **p);
unsigned int CombatantMotion_GetPrimaryTargetIndex(unsigned char **p);
void CombatantMotion_SetPrimaryTargetIndex(int self, unsigned char value);
unsigned int CombatantMotion_GetFallbackTargetIndex(char* p);
void CombatantMotion_SetFallbackTargetIndex(int self, unsigned char value);
int CombatantMotion_GetActiveStatus(char* p);
int CombatScene_FindCommandContainingActor(char* self, int id);
unsigned CombatScene_CollectCommandFinalTargets(char* self, unsigned index, int* output);
}

#define Range(v, a, b) (((v) >= (a) && (v) <= (b)) ? 1 : 0)

// Original: arm9/ov025 @ 0x021DFCE0; symbol: func_ov025_021dfce0; size: 0x2cc.
// Invalidates absent or inactive linked motion targets, then assigns a configured or nearest opposite-class combatant.
extern "C" void BattleScene_RefreshCombatantMotionTargets(char* control)
{
    GameState* game = GameState::GetInstance();
    Record records[12];
    int count = BattleScene_CollectMotionPlanningCombatants(*(void**)(control + 0x29c), records);
    for (int i = 0; i < count; i++) {
        char* object = records[i].object;
        ResetLinkedMotionFieldsAndRestorePosition((char**)object);
        if (CombatantMotion_GetPrimaryTargetIndex((unsigned char**)object) != 255) {
            char* target = (char*)game->GetCombatantByIndex(
                CombatantMotion_GetPrimaryTargetIndex((unsigned char**)object));
            if (!target)
                CombatantMotion_SetPrimaryTargetIndex((int)object, 255);
            else if (!CombatantMotion_GetActiveStatus(target))
                CombatantMotion_SetPrimaryTargetIndex((int)object, 255);
        }
        if (CombatantMotion_GetFallbackTargetIndex(object) != 255) {
            char* target = (char*)game->GetCombatantByIndex(
                CombatantMotion_GetFallbackTargetIndex(object));
            if (!target)
                CombatantMotion_SetFallbackTargetIndex((int)object, 255);
            else if (!CombatantMotion_GetActiveStatus(target))
                CombatantMotion_SetFallbackTargetIndex((int)object, 255);
        }
    }
    for (int i = 0; i < count; i++) {
        char* object = records[i].object;
        int target = CombatantMotion_GetPrimaryTargetIndex((unsigned char**)object);
        if (target != 255)
            continue;
        int configured[12];
        if (*(int*)(control + 0x55d8) <= CombatScene_FindCommandContainingActor(control, records[i].id)) {
            if ((int)CombatScene_CollectCommandFinalTargets(
                    control,
                    CombatScene_FindCommandContainingActor(control, records[i].id),
                    configured) > 0) {
                target = configured[0];
                CombatantMotion_SetPrimaryTargetIndex((int)object, (unsigned char)target);
            }
        }
        if (target != 255)
            continue;
        Vec position = *(Vec*)(object + 0x44);
        target = 255;
        int nearest = 0x400000;
        for (int j = 0; j < count; j++) {
            if (!CombatantMotion_GetActiveStatus(records[j].object))
                continue;
            int otherId = records[j].id;
            int id = records[i].id;
            int sameClass;
            if (Range(id, 0, 3) && Range(otherId, 0, 3))
                sameClass = 1;
            else if (Range(id, 192, 199) && Range(otherId, 192, 199))
                sameClass = 1;
            else
                sameClass = 0;
            if (sameClass)
                continue;
            Vec otherPosition = *(Vec*)(records[j].object + 0x44);
            int distance = Vector3fix_Distance(
                (const Vector3fix*)&position, (const Vector3fix*)&otherPosition);
            if (distance < nearest) {
                target = records[j].id;
                nearest = distance;
            }
        }
        CombatantMotion_SetFallbackTargetIndex((int)object, (unsigned char)target);
    }
}
