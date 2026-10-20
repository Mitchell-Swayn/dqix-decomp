#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {
void* Combat_GetCurrentCommandSlot(void*);
void Combat_InitializeCommandRecord(unsigned char*);
void* Combat_GetCommandActorSnapshot(void*, int);
void* Combat_GetIndexedActionTarget(void*, int);
bool GameObject_IsDead(void*);
int Combat_IsCombatantExcludedFromSelection(char*);
void* memcpy(void*, const void*, unsigned);
}

#pragma always_inline on
static inline void FlushDeferredDescriptorCommands(unsigned char* battle, unsigned char* commands, int index)
{
    for (; index < battle[0x8e10]; ++index) {
        unsigned char* output = (unsigned char*)Combat_GetCurrentCommandSlot(battle);
        if (!output) return;
        Combat_InitializeCommandRecord(output);
        unsigned char* command = commands + index * 40;
        unsigned char* snapshot = (unsigned char*)Combat_GetCommandActorSnapshot(command, 0);
        if (!snapshot) continue;
        if (!Combat_GetIndexedActionTarget(command, 0)) continue;
        int actorIndex = *(short*)(snapshot + 0x20);
        GameState* state = GameState::GetInstance();
        GameObject* actor = state->GetCombatantByIndex(actorIndex);
        if (!actor) continue;
        command[0x0b] |= 4;
        if (GameObject_IsDead(actor)) continue;
        if (Combat_IsCombatantExcludedFromSelection((char*)actor)) continue;
        memcpy(output, command, 40);
        ++*(int*)(battle + 0x8e24);
    }
    battle[0x8e09] = battle[0x8e10];
}

// Original: arm9/ov000 @ 0x0215B198; symbol: func_ov000_0215b198; size: 0xe0.
// Copies eligible deferred command records into the active command pool and advances its cursor.
extern "C" void Combat_FlushDeferredDescriptorActions(unsigned char* battle)
{
    FlushDeferredDescriptorCommands(battle, battle + 0x6d30, battle[0x8e09]);
}
