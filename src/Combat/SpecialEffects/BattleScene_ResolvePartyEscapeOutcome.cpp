#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/AllocatorUnion.h>
#include <Memory/SafeAllocator.h>
ARM
#pragma optimization_level 4
#pragma opt_rotateloops off

struct Entry { char reserved[0x4c]; int index; char rest[0x3f8]; };
struct State { char reserved[0x958]; Entry entries[4]; };
struct FourShorts { short v[4]; };
struct A { char pad[52]; unsigned value:24; unsigned rest:8; };

extern "C" {
void *Network_GetConnectionManager();
bool Network_IsSessionActive(int *param_1);
unsigned int PartySelection_GetMemberMask(unsigned char *p, unsigned int bit);
GameObject *GameState_FindIndexedObjectWithFlag1000(GameState *state, int index);
Entry *BattleScene_FindPartyCommandEntry(State *state, int index);
bool GameObject_IsDead(int param_1);
int BattleScene_HasRecoverableAilmentWithTimer5C(State *state);
bool CombatStatus_HasSleep(unsigned int *p);
unsigned Network_IsMemberActive(unsigned char *p, int key);
int GameObject_GetAssociatedPartyMemberIndex(int param_1);
int Combat_ClassifySpecialEncounterSpecies(unsigned char *p);
int Combat_RollEscapeSuccess(void *context, short *ids, unsigned char count);
bool GameState_CopyStatisticsRecord(void *out);
void Statistics_AddEscapeAttemptCount(A *p, unsigned int v);
void GameStats_AddPartyOutcomeCount(char *p, unsigned add);
int Combat_CollectEligiblePartyIds(void *context, short *output, int limit, int flags);
void Statistics_AddSuccessfulEscapeCount(char *p, unsigned add);
void GameStats_AddQualifiedPartyOutcomeCount(char *p, unsigned add);
int GameState_StoreStatisticsRecord(const void *in);
extern short BattleSceneResolvePartyEscapeOutcome_UnknownRoleInitializedBytes[];
extern short BattleSceneResolvePartyEscapeOutcome_UnknownRoleInitializedBytes_Variant2[];
}

static inline unsigned StatsWord14(GameObject *object)
{
    return *(unsigned *)((char *)object->currentStats_ + 0x14);
}

// Original: arm9/ov026 @ 0x021DD3DC; symbol: func_ov026_021dd3dc; size: 0x4cc.
// Classifies selected party command/status outcomes, filters eligible members, and updates escape statistics.
extern "C" int BattleScene_ResolvePartyEscapeOutcome(unsigned char *group, unsigned char *selection, State *records)
{
    GameState *game = GameState::GetInstance();
    void *connection = Network_GetConnectionManager();
    int statusCount = 0;
    int statuses[4];
    if (Combat_ClassifySpecialEncounterSpecies(group))
        return 1;
    if (!Network_IsSessionActive((int *)connection) || PartySelection_GetMemberMask(selection, 0)) {
        int status = 0;
        int i;
        for (i = 0; i < 4; i++) {
            if (PartySelection_GetMemberMask(selection, (unsigned char)i) && (i == 0 || GameState_FindIndexedObjectWithFlag1000(game, i))) {
                Entry *entry = BattleScene_FindPartyCommandEntry(records, i);
                if (entry && *((signed char *)entry + 0x1c) == 6) {
                    status = 1;
                    break;
                }
            }
        }
        if (!status) {
            for (i = 0; i < 4; i++) {
                if (PartySelection_GetMemberMask(selection, (unsigned char)i) && (i == 0 || GameState_FindIndexedObjectWithFlag1000(game, i))) {
                    GameObject *object = game->GetCombatantByIndex(i);
                    if (object && !(StatsWord14(object) & 0x80019)) {
                        status = 2;
                        break;
                    }
                }
            }
        }
        statuses[statusCount++] = status;
    }
    if (Network_IsSessionActive((int *)connection)) {
        int i;
        for (i = 1; i < 4; i++) {
            if (PartySelection_GetMemberMask(selection, (unsigned char)i) && !GameState_FindIndexedObjectWithFlag1000(game, i)) {
                GameObject *object = game->GetCombatantByIndex(i);
                if (object) {
                    Entry *entry = BattleScene_FindPartyCommandEntry(records, i);
                    if (entry) {
                        int status = 0;
                        if (*((signed char *)entry + 0x1c) == 6)
                            status = 1;
                        else if (!(StatsWord14(object) & 0x80019))
                            status = 2;
                        statuses[statusCount++] = status;
                    }
                }
            }
        }
    }
    int anyOne = 0;
    int n;
    for (n = 0; n < statusCount; n++) {
        if (statuses[n] == 1)
            anyOne = 1;
    }
    if (anyOne) {
        for (n = 0; n < statusCount; n++) {
            if (statuses[n] == 2)
                return 4;
        }
    }
    int outcome = 1;
    for (n = 0; n < statusCount; n++) {
        if (statuses[n] == 1) {
            FourShorts candidates = *(FourShorts *)BattleSceneResolvePartyEscapeOutcome_UnknownRoleInitializedBytes;
            int count = 0;
            int i = count;
            while (i < 4) {
                if (PartySelection_GetMemberMask(selection, (unsigned char)i) && Network_IsMemberActive((unsigned char *)connection, i)) {
                    candidates.v[count] = i;
                    count++;
                }
                i++;
            }
            i = 0;
            while (i < 4) {
                if (PartySelection_GetMemberMask(selection, (unsigned char)i)) {
                    GameObject *object = GameState_FindIndexedObjectWithFlag1000(game, i);
                    if (object && Network_IsMemberActive((unsigned char *)connection, GameObject_GetAssociatedPartyMemberIndex((int)object))) {
                        candidates.v[count] = i;
                        count++;
                    }
                }
                i++;
            }
            FourShorts eligible = *(FourShorts *)BattleSceneResolvePartyEscapeOutcome_UnknownRoleInitializedBytes_Variant2;
            {
                int pos, used;
                used = 0;
                pos = used;
                short *src = candidates.v;
                while (pos < count) {
                    short id = src[pos];
                    GameObject *object = game->GetCombatantByIndex(id);
                    if (object) {
                        if (!GameObject_IsDead((int)object)
                            && !BattleScene_HasRecoverableAilmentWithTimer5C((State *)object)
                            && !CombatStatus_HasSleep((unsigned int *)object->currentStats_)
                            && !(StatsWord14(object) & 0x80000)) {
                            eligible.v[used] = id;
                            used++;
                        }
                    }
                    pos++;
                }
                outcome = Combat_RollEscapeSuccess(group, eligible.v, (unsigned char)used) ? 2 : 3;
            }
            break;
        }
    }
    if (outcome != 1) {
        struct Statistics { char primary[104]; char secondary[72]; } statistics;
        GameState_CopyStatisticsRecord(&statistics);
        char *secondary = statistics.secondary;
        Statistics_AddEscapeAttemptCount((A *)&statistics, 1);
        GameStats_AddPartyOutcomeCount(secondary, 1);
        if (outcome == 2) {
            short ids[4];
            int collected = Combat_CollectEligiblePartyIds(group, ids, 4, 0);
            int blocked = 0;
            int i = 0;
            while (i < collected) {
                GameObject *object = game->GetCombatantByIndex(ids[i]);
                if (object && GameObject_IsDead((int)object)) {
                    blocked = 1;
                    break;
                }
                i++;
            }
            if (!blocked) {
                Statistics_AddSuccessfulEscapeCount(statistics.primary, 1);
                GameStats_AddQualifiedPartyOutcomeCount(secondary, 1);
            }
        }
        GameState_StoreStatisticsRecord(&statistics);
    }
    return outcome;
}
