#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
#pragma always_inline on
namespace {
struct GoldDescriptor { char prefix[0xc]; unsigned short gold; };
struct MonsterObject { char prefix[0x148]; GoldDescriptor* descriptor; };
struct ActionHistory { char prefix[0x1b]; unsigned char amount; };
struct CombatActionState { char prefix[8]; char* actorResults; ActionHistory* history; unsigned char* combat; };
inline bool IsPartyIndex(int index) { bool party; if (index >= 0 && index <= 3) party = true; else party = false; return party; }
}
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
extern "C" int Combat_GetLatestTargetFromHistory(char*);
extern "C" int GameState_IsProtagonistOrLinkedToProtagonist(void*,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
extern "C" void Combat_AppendActorResultToCategoryList(char*,void*,int);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E5C7C; symbol: func_ov024_021e5c7c; size: 0x204.
// Transfers up to one tenth of funds (capped at100) on a successful hit, recording
// the amount in action history and applying protagonist-linked inventory updates.
extern "C" void Combat_TryTransferGoldOnHit(CombatActionState* self,int actorId,void* unusedAction,int amount)
{
    if (amount <= 0) return;
    GameObject* actor = GetCombatantByID((int)self->combat, actorId);
    if (!actor) return;
    if ((int)(float)NextRandomMax((Random*)self->combat, 2) <= 0) return;
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return;
    unsigned char* inventory = (unsigned char*)GameState_GetIndexList(GameState::GetInstance());
    int targetId;
    int gold;
    ActionHistory* history = self->history;
    if (!history) return;
    targetId = Combat_GetLatestTargetFromHistory((char*)history);
    if (IsPartyIndex(targetId)) return;
    gold = 0;
    if (IsPartyIndex(actorId)) {
        MonsterObject* target = (MonsterObject*)Combat_FindIndexedMonsterObject(self->combat, targetId);
        if (target) {
            gold = (int)(0.1f * (float)(unsigned)target->descriptor->gold);
            if (gold > 100) gold = 100;
            if (gold > 0) {
                if (GameState_IsProtagonistOrLinkedToProtagonist(self->combat, actorId)) {
                    unsigned total = *(unsigned*)(inventory + 0xf6c) + gold;
                    if (total > 9999999) *(unsigned*)(inventory + 0xf6c) = 9999999;
                    else *(unsigned*)(inventory + 0xf6c) = total;
                }
                history->amount = gold;
                Combat_AppendResultMessage(self->combat, result, 0x172);
            }
        }
    } else {
        gold = (int)(0.1f * (float)*(unsigned*)(inventory + 0xf6c));
        if (gold > 100) gold = 100;
        if (gold > 0) {
            if (GameState_IsProtagonistOrLinkedToProtagonist(self->combat, targetId)) *(unsigned*)(inventory + 0xf6c) -= gold;
            history->amount = gold;
            Combat_AppendResultMessage(self->combat, result, 0x172);
        }
    }
    if (gold <= 0) return;
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, actor, (short)gold, 0, 0);
    Combat_AppendActorResultToCategoryList(self->actorResults, result, 2);
    ++self->combat[0x8e02];
}
#pragma force_active reset
