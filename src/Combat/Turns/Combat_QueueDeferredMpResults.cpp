#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma always_inline on
namespace {
// These projections name the fields observed by the pool and append helpers.
struct CommandRecord {
    short action;
    unsigned char unknown02[6];
    unsigned char actorCount, targetCount, unknown0A, flags;
    unsigned char unknown0C[4];
    void* actors;
    void* targets;
    unsigned short actionValue;
    unsigned char unknown1A[14];
};
struct ActorSnapshot {
    unsigned char unknown00[0x1c];
    short invalidIndex;
    short unknown1E;
    unsigned short actorIndex;
    unsigned short health, magic;
    unsigned char unknown26, pendingMagic;
    unsigned char unknown28[8];
    ActorSnapshot* next;
};
struct TargetRecord {
    unsigned char unknown00[0x0e];
    short actorIndex;
    unsigned char unknown10[7];
    unsigned char enabled;
    unsigned char unknown18[8];
    TargetRecord* next;
};
struct VitalStats {
    short health, magic;
    short ReadHealth() const { return health; }
    short ReadMagic() const { return magic; }
};
struct ActionDefinition {
    unsigned char unknown00[0x20];
    unsigned actionValue:10;
    unsigned otherBits:22;
};
}
extern "C" {
void* Combat_GetCurrentCommandSlot(void*);
void* Combat_GetCurrentActorSnapshotSlot(void*);
void* Combat_GetCurrentTargetRecordSlot(void*);
void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
void Combat_InitializeCommandRecord(unsigned char*);
void Combat_InitializeTargetResultRecord(void*);
void* Combat_GetCommandActorSnapshot(void*, int);
void Combat_AppendActorSnapshotToCommand(void*, void*);
void Combat_AppendActionTargetRecord(void*, void*);
void Combat_AppendTargetResultToCategoryList(void*, void*, int);
void Combat_PopulateResultFromCombatantSnapshot(void*, void*, void*, short, short, short, void*, void*, unsigned char);
void* memcpy(void*, const void*, unsigned);
void* memset(void*, int, unsigned);
}

#pragma force_active on
// Original: arm9/ov000 @ 0x0215C2D0; symbol: func_ov000_0215c2d0; size: 0x1fc.
// Converts actor snapshots with pending magic adjustments into result-bearing commands.
extern "C" void Combat_QueueDeferredMpResults(unsigned char* battle, unsigned char* previousCommand)
{
    for (int index = 0; index < previousCommand[8]; ++index) {
        ActorSnapshot* previous = (ActorSnapshot*)Combat_GetCommandActorSnapshot(previousCommand, index);
        if (!previous) continue;
        int actorIndex = (short)previous->actorIndex;
        GameState* state = GameState::GetInstance();
        GameObject* actor = state->GetCombatantByIndex(actorIndex);
        if (!actor) continue;
        int pendingMagic = previous->pendingMagic;
        if (pendingMagic <= 0) continue;
        CommandRecord* command = (CommandRecord*)Combat_GetCurrentCommandSlot(battle);
        if (!command) continue;
        Combat_InitializeCommandRecord((unsigned char*)command);
        ActorSnapshot* source = (ActorSnapshot*)Combat_GetCurrentActorSnapshotSlot(battle);
        if (!source) continue;
        memset(source, 0, 0x30);
        source->invalidIndex = -1;
        source->next = 0;
        TargetRecord* target = (TargetRecord*)Combat_GetCurrentTargetRecordSlot(battle);
        if (!target) continue;
        Combat_InitializeTargetResultRecord(target);
        unsigned char* result = (unsigned char*)Combat_ClearCurrentResultNodeSlot(battle);
        if (!result) continue;
        memset(result, 0, 0x20);
        *(void**)(result + 0x20) = 0;
        command->action = 0x3b0;
        memcpy(source, previous, sizeof(ActorSnapshot));
        *(int*)((unsigned char*)previous + 4) = 0;
        previous->pendingMagic = 0;
        previous->invalidIndex = -1;
        previous->unknown1E = 0;
        Combat_PopulateResultFromCombatantSnapshot(battle, result, actor, 0,
            ((VitalStats*)actor->currentStats_)->ReadHealth(),
            ((VitalStats*)actor->currentStats_)->ReadMagic(), 0, 0, 0);
        target->actorIndex = (unsigned short)previous->actorIndex;
        target->enabled = 1;
        Combat_AppendTargetResultToCategoryList(target, result, 0);
        command->flags |= 4;
        Combat_AppendActorSnapshotToCommand(command, source);
        Combat_AppendActionTargetRecord(command, target);
        ++*(int*)(battle + 0x8e24);
        ++battle[0x8e00];
        ++battle[0x8e01];
        ++battle[0x8e02];
    }
}
#pragma force_active off
