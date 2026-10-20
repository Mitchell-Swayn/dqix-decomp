#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct ActionTurnObject { unsigned char prefix[4]; short actorId; };
struct ActionTurnPartyObject { unsigned char prefix[0xc0]; unsigned char state; unsigned char unknownC1[0xcb]; unsigned flags18C; };
struct NibbleOwner;
extern "C" {
int CombatantMotion_TestPackedCategoryOutsideTwoThroughFive(const NibbleOwner*);
bool GameObject_HasBattleMotionFlag200(unsigned int**);
bool GameObject_IsBattleIdleMotionSuppressed(unsigned char*);
GameObject* GameState_GetObjectWithFlag100(GameState*, int);
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021DF9F4; symbol: func_ov025_021df9f4; size: 0xA8.
// Requires visible, eligible battle motion and excludes party state eight or flag one.
extern "C" int Combat_CanTurnForActionPresentation(ActionTurnObject* object)
{
    if (!object) return 0;
    int allowed = 0;
    if (((Object3D*)object)->IsVisible() &&
        CombatantMotion_TestPackedCategoryOutsideTwoThroughFive((const NibbleOwner*)object) &&
        !GameObject_HasBattleMotionFlag200((unsigned int**)object) &&
        !GameObject_IsBattleIdleMotionSuppressed((unsigned char*)object)) allowed = 1;
    int party = 0;
    if (object->actorId >= 0 && object->actorId <= 3) party = 1;
    if (party) {
        GameState* game = GameState::GetInstance();
        ActionTurnPartyObject* member = (ActionTurnPartyObject*)GameState_GetObjectWithFlag100(game, object->actorId);
        if (member && ((member->flags18C & 1) || member->state == 8)) allowed = 0;
    }
    return allowed;
}
#pragma force_active reset
