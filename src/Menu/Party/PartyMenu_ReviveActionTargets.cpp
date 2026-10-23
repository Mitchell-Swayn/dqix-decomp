#include <globaldefs.h>
ARM
// Preserve the original independent narrowing and reload operations.
#pragma force_active on
#define WORD(o) (*(int*)(self + (o)))
#define HALF(o) (*(short*)(self + (o)))
#define BYTE(o) (*(unsigned char*)(self + (o)))
#define SBYTE(o) (*(signed char*)(self + (o)))
#define POINTER(o) (*(char**)(self + (o)))
struct ActionTargetSelection { short kind; signed char caster; unsigned char count; signed char targets[4]; };
struct PartyActionResult { unsigned char status; unsigned char unknown01; short amount; unsigned char inactive; unsigned char unknown05; };
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* Network_GetConnectionManager();
extern "C" void PartyMenu_ClearTargetActionResult(void*);
extern "C" int PartyRoster_ContainsActiveObjectIndex(void*, int);
extern "C" int GameState_TestMatchingOrCompatibleObjectIdentifiers(void*, int, int);
extern "C" bool PartyMenu_HasTargetActionBlocker(int, int);
extern "C" int GameState_HasFlaggedObjectValue(void*, int);
extern "C" char* GameState_GetObjectWithFlag100(void*, int);
extern "C" int PartyMenu_ComputeRevivalSuccessRate(void*, void*, int);
extern "C" void* _Z11GetBTRandomv();
extern "C" int _Z13NextRandomMaxP6Randomi(void*, int);
extern "C" void GameObject_ReviveAndRestoreHP(void*, int, int);
extern "C" bool Network_IsSessionActive(int*);
extern "C" void Network_QueueCurrentPartyMemberState(int, int, int, int);
extern "C" void Field_RebuildActiveRosterAndCameraTarget(void*, int, int, int, int);
// Original: arm9/ov002 @ 0x02154230; symbol: func_ov002_02154230; size: 0x2c4.
// Applies revival attempts to eligible targets and records results or updates live party state.
extern "C" int PartyMenu_ReviveActionTargets(char* self, char* action, void* item, int alternate)
{
    if (!action) return 0;
    if (!item) return 0;
    char* state = _ZN9GameState11GetInstanceEv();
    void* resources = GameResources_GetInstance();
    void* roster = GameState_GetIndexList(state);
    void* network = Network_GetConnectionManager();
    PartyActionResult* results = (PartyActionResult*)(action + 8);
    int changed = 0;
    if (alternate) results = (PartyActionResult*)(action + 0x20);
    for (int i = 0; i < 4; ++i) PartyMenu_ClearTargetActionResult(results + i);
    for (int i = 0; i < (unsigned char)action[3]; ++i) {
        PartyActionResult* result = results + i;
        int target = (signed char)(action + i)[4];
        if (!PartyRoster_ContainsActiveObjectIndex(roster, target)) result->inactive = 1;
        if (!GameState_TestMatchingOrCompatibleObjectIdentifiers(self, target, (signed char)action[2])) { result->status = 1; continue; }
        if (PartyMenu_HasTargetActionBlocker((int)self, target)) { result->status = 2; continue; }
        if (GameState_HasFlaggedObjectValue(self, target)) continue;
        int recovery = 0;
        bool revive = false;
        char* member = GameState_GetObjectWithFlag100(state, target);
        if (!member) continue;
        short kind = *(short*)action;
        if (kind == 39) {
            revive = true;
            unsigned short maximum = *(unsigned short*)(*(char**)(member + 0x134) + 0x30);
            recovery = maximum / 2;
            if (maximum % 2 != 0) ++recovery;
        } else if (kind == 38) {
            revive = false;
            int caster = ((ActionTargetSelection*)action)->caster;
            int rate = PartyMenu_ComputeRevivalSuccessRate(self, item, caster);
            if (_Z13NextRandomMaxP6Randomi(_Z11GetBTRandomv(), 100) < rate) {
                revive = true;
                unsigned short maximum = *(unsigned short*)(*(char**)(member + 0x134) + 0x30);
                int product = maximum * (rate - 25);
                recovery = product / 100;
                if (product % 100 != 0) ++recovery;
            }
        } else if (kind == 407) {
            revive = true;
            recovery = 999;
        }
        if (!revive) continue;
        result->status = 3;
        if (result->inactive) { result->amount = recovery; result->status = 3; }
        else GameObject_ReviveAndRestoreHP(member, recovery, 1);
        if (Network_IsSessionActive((int*)network) && PartyRoster_ContainsActiveObjectIndex(roster, target)) Network_QueueCurrentPartyMemberState(target, 1, 0, 1);
        if (PartyRoster_ContainsActiveObjectIndex(roster, target)) Field_RebuildActiveRosterAndCameraTarget(resources, 1, 1, 1, 1);
        changed = 1;
    }
    return changed;
}
