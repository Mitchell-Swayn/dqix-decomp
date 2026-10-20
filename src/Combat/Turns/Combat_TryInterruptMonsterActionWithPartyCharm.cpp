#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Util/Random.h>
ARM
struct A;
extern "C" {
int Combat_CollectEligiblePartyIds(void*, short*, int, int);
int Combat_TestCombatantBlockingFlags(void*, int, int);
GameObject* GameState_GetObjectWithFlag100(GameState*, int);
float Combat_ComputePartyCharmInterruptionFactor(void*, int);
int CombatStatus_CanApplyActionRestriction(A*, unsigned, int);
bool CombatStatus_CanApplyParalysis(unsigned*);
bool CombatStatus_CanApplyConfusion(unsigned*);
// Original data: arm9/ov000 @ 0x02182A64 and 0x02182AA0; symbols: data_ov000_02182a64 / data_ov000_02182aa0.
extern const short CombatTryInterruptMonsterActionWithPartyCharm_UnknownRoleInitializedBytes[];
extern const unsigned char CombatTryInterruptMonsterActionWithPartyCharm_UnknownRoleInitializedBytes_Variant2[];
}
#pragma always_inline on
namespace {
int IsPartyActor(int index) { return index >= 0 && index <= 3; }
struct PartyIds { short values[4]; };
struct ReactionChoice { unsigned char weight, rate, mode, allowed; };
struct Choices { ReactionChoice values[3]; };
struct ReactionState {
    unsigned char unknown00[0x22];
    unsigned short low:12, mode:2, high:2;
    unsigned char unknown24[4];
    short actorIndex;
};
}
#pragma force_active on
// Original: arm9/ov000 @ 0x0215704C; symbol: func_ov000_0215704c; size: 0x23c.
// Tests party charm against a monster's susceptibility and records the selected interruption and party source.
extern "C" int Combat_TryInterruptMonsterActionWithPartyCharm(void* battle, int actorIndex)
{
    if (IsPartyActor(actorIndex)) return 0;
    PartyIds party = *(const PartyIds*)CombatTryInterruptMonsterActionWithPartyCharm_UnknownRoleInitializedBytes;
    int count = Combat_CollectEligiblePartyIds(battle, party.values, 4, 1);
    GameState* state = GameState::GetInstance();
    GameObject* actor = state->GetCombatantByIndex(actorIndex);
    if (!actor) return 0;
    if (Combat_TestCombatantBlockingFlags(battle, actorIndex, 0)) return 0;
    if (((unsigned char*)actor->currentStats_)[0x53] == 0) return 0;
    state = GameState::GetInstance();
    for (int index = 0; index < count; ++index) {
        GameObject* member = GameState_GetObjectWithFlag100(state, party.values[index]);
        if (!member) continue;
        float factor = Combat_ComputePartyCharmInterruptionFactor(battle, party.values[index]);
        float chance = factor * ((float)(unsigned)((unsigned char*)actor->currentStats_)[0x53] / 100.0f);
        if (chance > (float)NextRandomMax((Random*)battle, 100)) {
            Choices choices = *(const Choices*)CombatTryInterruptMonsterActionWithPartyCharm_UnknownRoleInitializedBytes_Variant2;
            choices.values[0].allowed = CombatStatus_CanApplyActionRestriction((A*)actor->currentStats_, 10, 0);
            choices.values[1].rate = ((unsigned char*)actor->currentStats_)[0x4e];
            choices.values[1].allowed = CombatStatus_CanApplyParalysis((unsigned*)actor->currentStats_);
            choices.values[2].rate = ((unsigned char*)actor->currentStats_)[0x4a];
            choices.values[2].allowed = CombatStatus_CanApplyConfusion((unsigned*)actor->currentStats_);
            int roll = NextRandomMax((Random*)battle, 100);
            for (int choice = 0; choice < 3; ++choice) {
                int weight = choices.values[choice].weight;
                if (weight > roll && choices.values[choice].rate != 0 && choices.values[choice].allowed != 0) {
                    ((ReactionState*)actor->currentStats_)->mode = choices.values[choice].mode;
                    ((ReactionState*)actor->currentStats_)->actorIndex = party.values[index];
                    return 1;
                }
                roll -= weight;
            }
        }
    }
    return 0;
}
#pragma force_active off
