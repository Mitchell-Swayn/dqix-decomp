#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Record; struct Owner; struct List; struct Lists; struct Node;
extern "C" {
GameObject* GameState_FindIndexedObjectWithFlag400(GameState*, int);
int Combat_CollectGroupIndicesByDescriptorFlags(char*, short*, int, unsigned);
int Combat_HasForcedTarget(void*);
bool GameObject_IsDead(void*);
int Combat_IsCombatantExcludedFromSelection(char*);
void GameObject_SetCombatRecoveryMarker(char*, int);
void CombatantState_ClearLinkedCombatEffect(unsigned char*);
void* Combat_GetCurrentCommandSlot(void*);
void Combat_InitializeCommandRecord(unsigned char*);
void* Combat_GetCurrentActorSnapshotSlot(void*);
char* Combat_GetCurrentTargetRecordSlot(char*);
void Combat_InitializeTargetResultRecord(Record*);
void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
void Combat_PopulateResultFromCombatantSnapshot(void*, Record*, Owner*, short, short, short, void*, void*, unsigned char);
void Combat_AppendResultMessage(void*, void*, unsigned short);
void Combat_AppendTargetResultToCategoryList(Lists*, Node*, int);
void Combat_AppendActorSnapshotToCommand(List*, Node*);
void Combat_AppendActionTargetRecord(Owner*, Node*);
void* memset(void*, int, unsigned);
// Original data: arm9/ov000 @ 0x02182C24; symbol: Combat_ClearForcedTargetsThatBecameInvalid_CombatantSelectionInitialIds.
extern const short Combat_ClearForcedTargetsThatBecameInvalid_CombatantSelectionInitialIds[];
}
#pragma always_inline on
namespace {
struct SelectionIds { short ids[8]; };
struct ActorSnapshot {
    unsigned char unknown00[0x1c];
    short invalidIndex;
    short unknown1E;
    unsigned short actorIndex, health, magic;
    unsigned char unknown26[10];
    ActorSnapshot* next;
};
struct TargetProjection { unsigned char unknown00[0x0e]; short actorIndex; unsigned char unknown10[7]; unsigned char enabled; };
struct SignedVitals { short health, magic; short ReadHealth() const { return health; } short ReadMagic() const { return magic; } };
struct ForcedTargetProjection { unsigned char unknown00[0x2e]; short actorIndex; };
}
#pragma force_active on
// Original: arm9/ov000 @ 0x0215C4CC; symbol: func_ov000_0215c4cc; size: 0x28c.
// Clears forced links to missing, dead, or unselectable targets and queues a result for each affected enemy.
extern "C" void Combat_ClearForcedTargetsThatBecameInvalid(unsigned char* battle)
{
    SelectionIds selection = *(const SelectionIds*)Combat_ClearForcedTargetsThatBecameInvalid_CombatantSelectionInitialIds;
    int count = Combat_CollectGroupIndicesByDescriptorFlags((char*)battle, selection.ids, 8, 1);
    for (int index = 0; index < count; ++index) {
        short actorIndex = selection.ids[index];
        GameState* state = GameState::GetInstance();
        GameObject* actor = GameState_FindIndexedObjectWithFlag400(state, actorIndex);
        if (!actor || !Combat_HasForcedTarget(actor)) continue;
        short targetIndex = ((ForcedTargetProjection*)actor->currentStats_)->actorIndex;
        state = GameState::GetInstance();
        GameObject* linkedTarget = state->GetCombatantByIndex(targetIndex);
        if (linkedTarget && !GameObject_IsDead(linkedTarget) && !Combat_IsCombatantExcludedFromSelection((char*)linkedTarget)) continue;
        GameObject_SetCombatRecoveryMarker((char*)actor, 1);
        CombatantState_ClearLinkedCombatEffect((unsigned char*)actor->currentStats_);
        unsigned char* command = (unsigned char*)Combat_GetCurrentCommandSlot(battle);
        if (!command) continue;
        Combat_InitializeCommandRecord(command);
        ActorSnapshot* source = (ActorSnapshot*)Combat_GetCurrentActorSnapshotSlot(battle);
        if (!source) continue;
        memset(source, 0, 0x30);
        source->invalidIndex = -1;
        source->next = 0;
        char* target = Combat_GetCurrentTargetRecordSlot((char*)battle);
        if (!target) continue;
        Combat_InitializeTargetResultRecord((Record*)target);
        unsigned char* result = (unsigned char*)Combat_ClearCurrentResultNodeSlot(battle);
        if (!result) continue;
        memset(result, 0, 0x20);
        *(void**)(result + 0x20) = 0;
        *(short*)command = 0x3ab;
        source->actorIndex = selection.ids[index];
        source->health = actor->currentStats_->primaryStats.currHP;
        source->magic = actor->currentStats_->primaryStats.currMP;
        Combat_PopulateResultFromCombatantSnapshot(battle, (Record*)result, (Owner*)actor, 0,
            ((SignedVitals*)actor->currentStats_)->ReadHealth(), ((SignedVitals*)actor->currentStats_)->ReadMagic(), 0, 0, 0);
        Combat_AppendResultMessage(battle, result, 0x164);
        ((TargetProjection*)target)->actorIndex = selection.ids[index];
        ((TargetProjection*)target)->enabled = 1;
        Combat_AppendTargetResultToCategoryList((Lists*)target, (Node*)result, 0);
        // The original advances this result cursor here and again after linking the command.
        ++battle[0x8e02];
        Combat_AppendActorSnapshotToCommand((List*)command, (Node*)source);
        Combat_AppendActionTargetRecord((Owner*)command, (Node*)target);
        ++*(int*)(battle + 0x8e24);
        ++battle[0x8e00];
        ++battle[0x8e01];
        ++battle[0x8e02];
    }
}
#pragma force_active off
