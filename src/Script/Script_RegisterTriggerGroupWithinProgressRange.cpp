#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
ARM
#pragma opt_propagation off // Preserve the separate current-progress snapshots.

struct CompactNode;
struct ExtendedNode;
struct Node;
struct TriggerGroup {
    unsigned short id;
    unsigned char startMajor, endMajor, startMinor, endMinor, key, reserved;
    CompactNode* compact;
    ExtendedNode* extended;
    TriggerGroup* next;
    TriggerGroup* group;
};
typedef char TriggerGroupSizeCheck[sizeof(TriggerGroup) == 24 ? 1 : -1];
extern "C" {
void Script_InitializeTriggerGroup(unsigned char*);
void DecodePackedScriptParametersToLists(SafeAllocator*, int, Script::Parameter*, CompactNode**, ExtendedNode**);
void LinkedList_AppendNodeToMatchingKeyGroup(void*, Node*);
extern unsigned char ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/main @ 0x0205F9CC; symbol: func_0205f9cc; size: 0x100.
extern "C" int Script_RegisterTriggerGroupWithinProgressRange(Script::Parameter* params, int count)
{
    int id = params[0].ToInt();
    if (id != *(int*)(ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage + 0x484)) return 0;
    int startMajor = params[1].ToInt();
    int startMinor = params[2].ToInt();
    int endMajor = params[3].ToInt();
    int endMinor = params[4].ToInt();
    int currentMajor = *(int*)(ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage + 0x488);
    int currentMinor = *(int*)(ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage + 0x48c);
    int upper = endMajor * 1000 + endMinor;
    int current = currentMajor * 1000 + currentMinor;
    int lower = startMajor * 1000 + startMinor;
    if (current < lower || upper < current) return 0;
    SafeAllocator* allocator = *(SafeAllocator**)(ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage + 0x480);
    TriggerGroup* entry = (TriggerGroup*)allocator->Allocate(sizeof(TriggerGroup));
    if (!entry) return 1;
    Script_InitializeTriggerGroup((unsigned char*)entry);
    entry->id = id;
    entry->startMajor = startMajor;
    entry->endMajor = endMajor;
    entry->startMinor = startMinor;
    entry->endMinor = endMinor;
    entry->key = params[5].ToInt();
    DecodePackedScriptParametersToLists(allocator, count - 6, params + 6, &entry->compact, &entry->extended);
    LinkedList_AppendNodeToMatchingKeyGroup(ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage, (Node*)entry);
    return 1;
}
