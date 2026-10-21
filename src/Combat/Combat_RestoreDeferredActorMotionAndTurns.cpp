#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct CombatStatusMaskWords {
    unsigned word0;
    unsigned word1;
};

extern "C" {
unsigned BattleScene_GetActiveInstance();
void* BattleScene_GetMenuController(unsigned char* self);
int Combat_CollectEligiblePartyIds(void* context, short* output, int limit, int flags);
int Combat_CollectPresentEnemyIndices(void*, short* output, int capacity, int);
unsigned int CombatantMotion_GetSavedActionDescriptor(unsigned int** p);
void CombatantMotion_SetSavedActionDescriptor(int self, unsigned int value);
int CombatantMotion_HasInheritedAlphaRestoreRequest(char* p);
void CombatantMotion_ClearInheritedAlphaRestoreRequest(unsigned int** p);
unsigned int CombatantMotion_GetDeferredTurnTargetIndex(char* p);
void CombatantMotion_SetDeferredTurnTargetIndex(int self, unsigned char value);
void Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(Object3D* p, int id, int turn);
char* BattleMenu_FindPartyPanelByCombatantIndex(void* object, int index);
void BattleMenu_BroadcastPartyDisplayStats(void* record);
void BattleMenu_SetRestoredActionAttribute(void* object, unsigned char value);
void CombatScene_ApplyCombatantStatusAppearance(void* scene, int unused, void* combatant, unsigned flags,
    int attribute, int extra, CombatStatusMaskWords words, int apply);
}

// Original: arm9/ov025 @ 0x021EB8E8; symbol: func_ov025_021eb8e8; size: 0x178.
// Restores saved action descriptors, inherited alpha, and deferred turn facing
// for collected party and enemy combatants.
extern "C" void Combat_RestoreDeferredActorMotionAndTurns(char* self)
{
    GameState* game = GameState::GetInstance();
    unsigned scene = BattleScene_GetActiveInstance();
    void* menu = BattleScene_GetMenuController((unsigned char*)scene);
    short ids[16];
    int count = 0;
    count += Combat_CollectEligiblePartyIds(*(void**)(self + 0xc), ids, 0x10, count);
    count += Combat_CollectPresentEnemyIndices(*(void**)(self + 0xc), ids + count, 0x10 - count, 0);
    short* cursor = ids;
    for (int i = 0; i < count; i++) {
        char* object = (char*)game->GetCombatantByIndex(*cursor);
        if (object) {
            unsigned char* descriptor = (unsigned char*)CombatantMotion_GetSavedActionDescriptor((unsigned int**)object);
            if (descriptor) {
                unsigned flags = *(unsigned*)(descriptor + 0x18) & ~0x80000u;
                CombatScene_ApplyCombatantStatusAppearance(
                    (void*)scene,
                    0,
                    object,
                    flags,
                    descriptor[0x1d],
                    descriptor[0x1e],
                    *(CombatStatusMaskWords*)descriptor,
                    1);
                char* panel = BattleMenu_FindPartyPanelByCombatantIndex(menu, *cursor);
                if (panel) {
                    *(unsigned*)(panel + 0x28) = flags;
                    BattleMenu_BroadcastPartyDisplayStats(panel);
                    BattleMenu_SetRestoredActionAttribute(panel, descriptor[0x1d]);
                    panel[0x2f] = descriptor[0x1e];
                }
                CombatantMotion_SetSavedActionDescriptor((int)object, 0);
            }
            if (CombatantMotion_HasInheritedAlphaRestoreRequest(object)) {
                ((Object3D*)object)->SetInheritedAlpha(0x1f);
                CombatantMotion_ClearInheritedAlphaRestoreRequest((unsigned int**)object);
            }
            if (CombatantMotion_GetDeferredTurnTargetIndex(object) != 0xff) {
                unsigned int target = CombatantMotion_GetDeferredTurnTargetIndex(object);
                Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation((Object3D*)object, (int)target, 1);
                CombatantMotion_SetDeferredTurnTargetIndex((int)object, 0xff);
            }
        }
        cursor++;
    }
}
