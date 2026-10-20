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
static inline void FlushDeferredMpCommands(unsigned char* battle, unsigned char* commands, int index)
{
    for (; index < battle[0x8e0f]; ++index) {
        unsigned char* output = (unsigned char*)Combat_GetCurrentCommandSlot(battle);
        if (!output) return;
        Combat_InitializeCommandRecord(output);
        int offset = index * 40;
        unsigned char* command = commands + offset;
        unsigned char* snapshot = (unsigned char*)Combat_GetCommandActorSnapshot(command, 0);
        if (!snapshot) continue;
        if (!Combat_GetIndexedActionTarget(command, 0)) continue;
        int actorIndex = *(short*)(snapshot + 0x20);
        GameState* state = GameState::GetInstance();
        GameObject* actor = state->GetCombatantByIndex(actorIndex);
        if (!actor) return;
        
        if (GameObject_IsDead(actor)) return;
        if (Combat_IsCombatantExcludedFromSelection((char*)actor)) return;
        memcpy(output, command, 40);
        ++*(int*)(battle + 0x8e24);
    }
    battle[0x8e0a] = battle[0x8e0f];
}

// Original: arm9/ov000 @ 0x0215AE80; symbol: func_ov000_0215ae80; size: 0xd4.
// Copies eligible deferred command records into the active command pool and advances its cursor.
extern "C" void Combat_FlushDeferredMpAdjustmentActions(unsigned char* battle)
{
    FlushDeferredMpCommands(battle, battle + 0x7770, battle[0x8e0a]);
}
