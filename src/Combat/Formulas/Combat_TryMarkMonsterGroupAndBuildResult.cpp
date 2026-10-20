#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Util/Random.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x24]; unsigned successMessage:10, middleMessage:10, failureMessage:10, rest24:2; };
struct ResultHeader { char prefix[0x1c]; unsigned short message; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[4]; ResultHeader* header; char padding8[4]; ResultFlags* flags; unsigned char* combat; char padding14[0x6e - 0x14]; unsigned char messageQueued; };
struct MonsterObject { char prefix[0x17c]; unsigned char group; };
struct MonsterGroup { unsigned short species; char padding[0x16-2]; unsigned char marked; char rest; };
struct MonsterRecord { char prefix[2]; unsigned char category; };
}
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
extern "C" void* MonsterBattleData_FindEntryById(void*,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E16A4; symbol: func_ov024_021e16a4; size: 0x180.
// Marks a monster group with a 50 or 100 percent roll and chooses one shared result message.
extern "C" void* Combat_TryMarkMonsterGroupAndBuildResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action)
{
    MonsterObject* target = (MonsterObject*)Combat_FindIndexedMonsterObject(self->combat, targetId);
    if (!target) return 0;
    if (!self->messageQueued) {
        int groupIndex = target->group;
        if (groupIndex >= 3) return 0;
        MonsterGroup* group = (MonsterGroup*)(self->combat + 0x81b4) + groupIndex;
        unsigned char* table = *(unsigned char**)(self->combat + 0x8e18) + 0x284;
        MonsterRecord* record = (MonsterRecord*)MonsterBattleData_FindEntryById(table + 0x400, group->species);
        if (group->marked || (record && record->category == 7)) {
            self->header->message = action->failureMessage;
            self->messageQueued = 1;
        } else {
            int chance = 100;
            unsigned char* environment = *(unsigned char**)(self->combat + 0x8e18);
            if (environment && (environment[0x24] || environment[0x25])) chance = 50;
            if (NextRandomMax((Random*)self->combat, 100) < chance) {
                self->header->message = action->successMessage;
                self->messageQueued = 1;
                group->marked = 1;
            } else {
                self->header->message = action->failureMessage;
                self->messageQueued = 1;
            }
        }
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
