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
void* Util_GetNestedListNodeAtIndex(void*, int, int);
int Util_TestSplitWordBit(unsigned long long*, unsigned);
void Combat_AppendActorResultToCategoryList(char*, void*, int);
}
#pragma always_inline on
namespace {
struct ActorSnapshot {
    void* categoryHeads[6];
    unsigned char unknown18[4];
    short invalidIndex, unknown1E;
    unsigned short actorIndex, health, magic;
    unsigned char categoryCounts[6];
    unsigned char unknown2C[4];
    ActorSnapshot* next;
};
struct TargetProjection { unsigned char unknown00[0x0e]; short actorIndex; unsigned char unknown10[7]; unsigned char enabled; };
struct SignedVitals { short health, magic; short ReadHealth() const { return health; } short ReadMagic() const { return magic; } };
}
#pragma force_active on
// Original: arm9/ov000 @ 0x0215BF5C; symbol: func_ov000_0215bf5c; size: 0x374.
// Transfers pending damage and additional effects into a separately queued command.
extern "C" void Combat_QueueDeferredDamageResults(unsigned char* battle, unsigned char* previousCommand)
{
    for (int index = 0; index < previousCommand[8]; ++index) {
        ActorSnapshot* previous = (ActorSnapshot*)Combat_GetCommandActorSnapshot(previousCommand, index);
        if (!previous) continue;
        unsigned long long* deferred;
        bool blocked, includeAdditional;
        unsigned char* command;
        char* target;
        unsigned char* result;
        short actorIndex = previous->actorIndex;
        GameState* state = GameState::GetInstance();
        GameObject* actor = state->GetCombatantByIndex(actorIndex);
        if (!actor) continue;
        int pendingCount = previous->categoryCounts[2];
        // The original uses the outer snapshot index to select this category node.
        deferred = (unsigned long long*)Util_GetNestedListNodeAtIndex(previous, index, 2);
        blocked = false;
        includeAdditional = false;
        if (deferred && (Util_TestSplitWordBit(deferred, 0x22) || Util_TestSplitWordBit(deferred, 0x25))) blocked = true;
        if (!blocked && previous->categoryCounts[3] == 0) {
            includeAdditional = true;
            pendingCount += previous->categoryCounts[4];
        }
        if (pendingCount <= 0) continue;
        command = (unsigned char*)Combat_GetCurrentCommandSlot(battle);
        if (!command) continue;
        Combat_InitializeCommandRecord(command);
        ActorSnapshot* source = (ActorSnapshot*)Combat_GetCurrentActorSnapshotSlot(battle);
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
        bool moved = false;
        if (deferred && ((*deferred & 2ULL) != 0 || (*deferred & 4ULL) != 0 || (*deferred & 0x10ULL) != 0 || (*deferred & 0x2000ULL) != 0)) {
            Combat_AppendActorResultToCategoryList((char*)source, deferred, 2);
            previous->categoryHeads[2] = 0;
            previous->categoryCounts[2] = 0;
            moved = true;
        }
        if (!moved && !includeAdditional) continue;
        if (includeAdditional) {
            source->categoryHeads[4] = previous->categoryHeads[4];
            source->categoryCounts[4] = previous->categoryCounts[4];
            previous->categoryHeads[4] = 0;
            previous->categoryCounts[4] = 0;
        }
        source->actorIndex = previous->actorIndex;
        source->magic = previous->magic;
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
    }
}
#pragma force_active off
