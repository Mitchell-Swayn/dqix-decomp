#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x20]; unsigned reserved20:20, partyMessage:10, rest20:2; unsigned monsterMessage:10, rest24:22; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct ResultHeader { char prefix[0x1a]; unsigned short partyMessage, monsterMessage; };
struct CombatActionState { char prefix[4]; ResultHeader* header; char padding8[4]; ResultFlags* flags; unsigned char* combat; char padding14[0x6e - 0x14]; unsigned char messageQueued; };
struct EncounterCount { unsigned char low:4, count:2, high:2; };
struct RewardRecord { char prefix[8]; int reward; };
}
extern "C" void* MonsterBattleData_FindEntryById(void*,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E1CBC; symbol: func_ov024_021e1cbc; size: 0x12c.
// Selects descriptor messages when any encountered monster group has a reward, then builds the target result.
extern "C" void* Combat_SelectMonsterGroupRewardMessageAndBuildResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    int hasReward = 0;
    unsigned char* table = *(unsigned char**)(self->combat + 0x8e18) + 0x284;
    for (int group = 0; group < ((EncounterCount*)(self->combat + 0x81b1))->count; ++group) {
        RewardRecord* record = (RewardRecord*)MonsterBattleData_FindEntryById(table + 0x400, *(unsigned short*)(self->combat + group * 0x18 + 0x81b4));
        if (record && record->reward) hasReward = 1;
    }
    if (!hasReward) {
        self->header->monsterMessage = 31;
        self->header->partyMessage = 31;
    } else {
        self->header->monsterMessage = action->monsterMessage;
        self->header->partyMessage = action->partyMessage;
    }
    self->messageQueued = 1;
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
