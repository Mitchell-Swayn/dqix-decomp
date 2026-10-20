#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
namespace {
struct ResultHeader { char prefix[6]; unsigned short target; char padding[0x1a - 8]; unsigned short previousMessage, message; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[4]; ResultHeader* header; char pad08[4]; ResultFlags* flags; unsigned char* combat; int appliedCount; char padding[0x6e - 0x18]; unsigned char messageQueued; };
struct MonsterGroup { unsigned short species; char padding[0x16 - 2]; unsigned char firstMark, secondMark; };
struct MonsterRecord { unsigned short species; unsigned char firstCategory, secondCategory; unsigned reserved; unsigned firstValue; unsigned short secondValue; };
struct GroupCounts { unsigned char groups:4, records:2, rest:2; };
struct ChanceWeights { int values[3]; };
}
// Original data: arm9/ov024 @ 0x021FE6EC; symbol: data_ov024_021fe6ec.
// Three original signed probability weights10,40,50 copied locally by this handler.
extern "C" ChanceWeights CombatRollMonsterGroupMarkersAndSelectSummaryMessage_UnknownRoleInitializedBytes;
extern "C" void* MonsterBattleData_FindEntryById(void*,int);
extern "C" int Combat_FindEligibleEnemyWithLeastHomeX(void*);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E2298; symbol: func_ov024_021e2298; size: 0x2e8.
// Rolls shared group markers once and selects summary feedback from available
// record rewards and marker categories, then builds the target snapshot.
extern "C" void* Combat_RollMonsterGroupMarkersAndSelectSummaryMessage(CombatActionState* self,int unusedActor,int targetId,void* unusedAction)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    unsigned char* combat = self->combat;
    if (!self->messageQueued) {
        unsigned char* table = *(unsigned char**)(combat + 0x8e18) + 0x284;
        ChanceWeights weights = CombatRollMonsterGroupMarkersAndSelectSummaryMessage_UnknownRoleInitializedBytes;
        int sample = NextRandomMax((Random*)combat, 100);
        int bucket = 0;
        for (; bucket < 3; ++bucket) {
            if (weights.values[bucket] >= sample) break;
            sample -= weights.values[bucket];
        }
        unsigned char flags = 0;
        int groups = ((GroupCounts*)(self->combat + 0x81b1))->groups;
        for (int i = 0; i < ((GroupCounts*)(self->combat + 0x81b1))->records; ++i) {
            MonsterGroup* group = (MonsterGroup*)(self->combat + 0x81b4) + i;
            MonsterRecord* record = (MonsterRecord*)MonsterBattleData_FindEntryById(table + 0x400, group->species);
            if (!record) continue;
            if (record->firstValue) flags |= 1;
            if (record->secondValue) flags |= 2;
            if (record->firstCategory < 7) {
                if (bucket == 1) { flags |= 4; group->firstMark = 1; }
            }
            if (record->secondCategory < 7) {
                if (bucket == 0) { flags |= 8; group->secondMark = 1; }
            }
        }
        self->messageQueued = 1;
        ++self->appliedCount;
        self->header->message = 0x1f;
        if (flags & 1) {
            self->header->message = 0x263;
            if (flags & 2) {
                self->header->message = 0x1be;
                if (flags & 4) {
                    if (groups > 1) self->header->message = 0x1bf;
                    else self->header->message = 0x224;
                } else if (flags & 8) {
                    if (groups > 1) self->header->message = 0x1c0;
                    else self->header->message = 0x225;
                }
            } else {
                if (flags & 4) {
                    if (groups > 1) self->header->message = 0x266;
                    else self->header->message = 0x268;
                } else if (flags & 8) {
                    if (groups > 1) self->header->message = 0x267;
                    else self->header->message = 0x269;
                }
            }
        } else {
            if (flags & 4) {
                if (groups > 1) self->header->message = 0x264;
                else self->header->message = 0x26a;
            } else if (flags & 8) {
                if (groups > 1) self->header->message = 0x265;
                else self->header->message = 0x26b;
            }
        }
        self->header->previousMessage = self->header->message;
        self->header->target = Combat_FindEligibleEnemyWithLeastHomeX(self->combat);
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
