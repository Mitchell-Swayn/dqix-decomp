#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
namespace {
struct ResultHeader { char prefix[0x1a]; unsigned short message; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[4]; ResultHeader* header; char padding8[4]; ResultFlags* flags; unsigned char* combat; char padding14[0x6e - 0x14]; unsigned char messageQueued; };
struct EightIds { short values[8]; };
}
// Original data: arm9/ov024 @ 0x021FE728; symbol: data_ov024_021fe728.
extern "C" unsigned char CombatRollSceneModeFromCombinedPartyLevels_UnknownRoleInitializedBytes[];
// Original data: arm9/ov024 @ 0x021FE758; symbol: data_ov024_021fe758.
extern "C" unsigned char CombatRollSceneModeFromCombinedPartyLevels_UnknownRoleInitializedBytes_Variant2[];
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned short GameObject_GetCurrentVocationLevel(int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" void BattleScene_CreatePresetMonsterRoster(unsigned,int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E20C0; symbol: func_ov024_021e20c0; size: 0x1d8.
// Selects a weighted roster preset from the combined eligible party levels and creates the scene roster.
extern "C" void* Combat_RollSceneModeFromCombinedPartyLevels(CombatActionState* self,int unusedActor,int targetId)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    unsigned scene = BattleScene_GetActiveInstance();
    EightIds ids = *(EightIds*)CombatRollSceneModeFromCombinedPartyLevels_UnknownRoleInitializedBytes;
    int count = Combat_CollectEligiblePartyIds(self->combat, ids.values, 4, 0);
    if (count <= 0) return 0;
    GameState* state = GameState::GetInstance();
    unsigned short levelSum = 0;
    for (int index = 0; index < count; ++index) {
        GameObject* actor = GameState_GetObjectWithFlag100(state, ids.values[index]);
        if (actor) levelSum += GameObject_GetCurrentVocationLevel((int)actor);
    }
    int band = 0;
    if (levelSum >= 201) band = 3;
    else if (levelSum >= 121) band = 2;
    else if (levelSum >= 61) band = 1;
    unsigned char sample = NextRandomMax((Random*)self->combat, 100);
    unsigned char* weights = CombatRollSceneModeFromCombinedPartyLevels_UnknownRoleInitializedBytes_Variant2 + band * 4;
    unsigned char mode = 0;
    for (; mode < 4; ++mode) {
        if (weights[mode] > sample) break;
        sample -= weights[mode];
    }
    if (mode >= 4) mode = 3;
    int monsters = Combat_CollectGroupIndicesByDescriptorFlags((char*)self->combat, ids.values, 8, 1);
    BattleScene_CreatePresetMonsterRoster(scene, mode, 1);
    if (monsters > 0) {
        if (monsters > 1) self->header->message = 0x221;
        else self->header->message = 0x220;
        self->messageQueued = 1;
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
