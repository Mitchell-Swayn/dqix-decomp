#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#pragma thumb off
struct PartyPositionActor {
    Object3D object;
    unsigned char reservedAC[0x15];
    unsigned char placementState : 2;
    unsigned char otherState : 6;
    unsigned char reservedC2[0xbb];
    unsigned char partySelection;
};
extern "C" {
int ReadEnabledPackedField17DSelector(unsigned char*);
void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);
}
// Signed division preserves truncation toward zero for negative radii.
static inline fix32_t PartySpacing(fix32_t memberRadius, fix32_t ownRadius)
{
    fix32_t memberQuarter = memberRadius / 4;
    fix32_t ownHalf = ownRadius / 2;
    return memberQuarter + ownHalf;
}
// Original: arm9/main @ 0x0207964C; symbol: func_0207964c; size: 0xC4.
// Place the enabled actor in front of its selected party member, facing back
// toward that member. The member's low placement-state bit inhibits movement.
extern "C" void GameObject_MoveInFrontOfSelectedPartyMember(PartyPositionActor* self)
{
    if (self->partySelection & 8) {
        GameState* state = GameState::GetInstance();
        PartyPositionActor* member = (PartyPositionActor*)state->GetPartyMemberByIndex(
            ReadEnabledPackedField17DSelector((unsigned char*)self));
        if (member && !(member->placementState & 1)) {
            fix32_t memberRadius = member->object.GetRadius();
            fix32_t ownRadius = self->object.GetRadius();
            Vector3fix position = member->object.GetPointInFront(PartySpacing(memberRadius,ownRadius));
            fix32_t angle = fix32ReduceAngle0To2Pi(member->object.rotation_.y + 0x3244);
            self->object.position_ = position;
            Object3D_SetNormalizedAngleAndUpdatePosition((char*)self,angle);
        }
    }
}
