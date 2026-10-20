#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Record; struct Owner; struct List; struct Lists; struct Node;
extern "C" {
void* Combat_GetCurrentCommandSlot(void*);
void Combat_InitializeCommandRecord(unsigned char*);
void* Combat_GetCurrentActorSnapshotSlot(void*);
char* Combat_GetCurrentTargetRecordSlot(char*);
void Combat_InitializeTargetResultRecord(Record*);
void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
void Combat_PopulateResultFromCombatantSnapshot(void*, Record*, Owner*, short, short, short, void*, void*, unsigned char);
void Combat_AppendTargetResultToCategoryList(Lists*, Node*, int);
void Combat_AppendActorSnapshotToCommand(List*, Node*);
void Combat_AppendActionTargetRecord(Owner*, Node*);
void* memset(void*, int, unsigned);
void* Combat_GetCommandActorSnapshot(void*, int);
void* memcpy(void*, const void*, unsigned);
void Combat_AppendResultMessage(void*, void*, unsigned short);
}
#pragma always_inline on
namespace {
struct ActorSnapshot {
    void* categoryHeads[6];
    unsigned char unknown18[4];
    short invalidIndex, unknown1E;
    unsigned short actorIndex, health, magic;
    unsigned char categoryCounts[6];
    unsigned char unknown2C, marker, unknown2E[2];
    ActorSnapshot* next;
};
struct TargetProjection { unsigned char unknown00[0x0e]; short actorIndex; unsigned char unknown10[7]; unsigned char enabled; };
struct SignedVitals { short health, magic; short ReadHealth() const { return health; } short ReadMagic() const { return magic; } };
}
#pragma force_active on
// Original: arm9/ov000 @ 0x0215BBBC; symbol: func_ov000_0215bbbc; size: 0x3a0.
// Moves all pending categories except MP into a separate command and reports the copied marker.
extern "C" void Combat_QueueDeferredNonMpResults(unsigned char* battle, unsigned char* previousCommand)
{
    for (int index = 0; index < previousCommand[8]; ++index) {
        ActorSnapshot* previous = (ActorSnapshot*)Combat_GetCommandActorSnapshot(previousCommand, index);
        if (!previous) continue;
        unsigned char* command;
        ActorSnapshot* source;
        char* target;
        unsigned char* result;
        short actorIndex = previous->actorIndex;
        GameState* state = GameState::GetInstance();
        GameObject* actor = state->GetCombatantByIndex(actorIndex);
        if (!actor) continue;
        int pendingCount = 0;
        for (int category = 0; category < 6; ++category) {
            if (category != 1) pendingCount += previous->categoryCounts[category];
        }
        if (pendingCount <= 0) continue;
        command = (unsigned char*)Combat_GetCurrentCommandSlot(battle);
        if (!command) continue;
        Combat_InitializeCommandRecord(command);
        source = (ActorSnapshot*)Combat_GetCurrentActorSnapshotSlot(battle);
        if (!source) continue;
        memset(source, 0, 0x30);
        source->invalidIndex = -1;
        source->next = 0;
        target = Combat_GetCurrentTargetRecordSlot((char*)battle);
        if (!target) continue;
        Combat_InitializeTargetResultRecord((Record*)target);
        result = (unsigned char*)Combat_ClearCurrentResultNodeSlot(battle);
        if (!result) continue;
        memset(result, 0, 0x20);
        *(void**)(result + 0x20) = 0;
        *(short*)command = 0x3ae;
        memcpy(source, previous, 0x34);
        for (int category = 0; category < 6; ++category) {
            if (category != 1) {
                previous->categoryHeads[category] = 0;
                previous->categoryCounts[category] = 0;
            }
        }
        previous->invalidIndex = -1;
        previous->unknown1E = 0;
        previous->marker = 0;
        source->categoryHeads[1] = 0;
        source->categoryCounts[1] = 0;
        Combat_PopulateResultFromCombatantSnapshot(battle, (Record*)result, (Owner*)actor, 0,
            ((SignedVitals*)actor->currentStats_)->ReadHealth(), ((SignedVitals*)actor->currentStats_)->ReadMagic(), 0, 0, 0);
        ((TargetProjection*)target)->actorIndex = previous->actorIndex;
        ((TargetProjection*)target)->enabled = 1;
        Combat_AppendTargetResultToCategoryList((Lists*)target, (Node*)result, 0);
        command[0xb] |= 4;
        Combat_AppendActorSnapshotToCommand((List*)command, (Node*)source);
        Combat_AppendActionTargetRecord((Owner*)command, (Node*)target);
        ++*(int*)(battle + 0x8e24);
        ++battle[0x8e00];
        ++battle[0x8e01];
        ++battle[0x8e02];
        if (source->marker != 1) continue;
        command = (unsigned char*)Combat_GetCurrentCommandSlot(battle);
        if (!command) continue;
        Combat_InitializeCommandRecord(command);
        source = (ActorSnapshot*)Combat_GetCurrentActorSnapshotSlot(battle);
        if (!source) continue;
        memset(source, 0, 0x30);
        source->invalidIndex = -1;
        source->next = 0;
        target = Combat_GetCurrentTargetRecordSlot((char*)battle);
        if (!target) continue;
        Combat_InitializeTargetResultRecord((Record*)target);
        result = (unsigned char*)Combat_ClearCurrentResultNodeSlot(battle);
        if (!result) continue;
        memset(result, 0, 0x20);
        *(void**)(result + 0x20) = 0;
        bool partyActor = false;
        if (previous->actorIndex <= 3) partyActor = true;
        *(short*)command = partyActor ? 0x39c : 0x39d;
        source->actorIndex = previous->actorIndex;
        source->health = actor->currentStats_->primaryStats.currHP;
        source->magic = actor->currentStats_->primaryStats.currMP;
        command[0xb] |= 4;
        Combat_PopulateResultFromCombatantSnapshot(battle, (Record*)result, (Owner*)actor, 0,
            ((SignedVitals*)actor->currentStats_)->ReadHealth(), ((SignedVitals*)actor->currentStats_)->ReadMagic(), 0, 0, 0);
        Combat_AppendResultMessage(battle, result, 0x35);
        ((TargetProjection*)target)->actorIndex = previous->actorIndex;
        ((TargetProjection*)target)->enabled = 1;
        Combat_AppendTargetResultToCategoryList((Lists*)target, (Node*)result, 0);
        // This second result advances twice, matching the original cursor sequence.
        ++battle[0x8e02];
        Combat_AppendActorSnapshotToCommand((List*)command, (Node*)source);
        Combat_AppendActionTargetRecord((Owner*)command, (Node*)target);
        ++*(int*)(battle + 0x8e24);
        ++battle[0x8e00];
        ++battle[0x8e01];
        ++battle[0x8e02];
        source->marker = 0;
    }
}
#pragma force_active off
