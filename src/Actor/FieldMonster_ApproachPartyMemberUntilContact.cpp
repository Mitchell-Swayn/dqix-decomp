#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Vector.h>
#include <System/Matrix.h>
ARM
#pragma always_inline on

typedef unsigned int undefined4;
struct Object;
struct Owner;
union Vec {
    struct {
        int x, y, z;
    };
    int words[3];
};

extern "C" {
void *Network_GetConnectionManager();
ARM bool Network_IsSessionActive(int *param_1);
int Network_GetLocalMemberId(char *p);
ARM int Object_ComputeHeadingDotProduct(char *p, const int *angle);
void SetObjectAngleAndClearFlagC48000(void *object, int angle);
ARM void GameObject_ChangeMotionStateAndRefreshAnimation(Owner *object, unsigned value);
ARM int GameObject_GetWallContactGeometry(int p);
ARM void GameObject_GetConnectedMemberPosition(Vec *out, Object *p);
ARM undefined4 GameObject_GetEncounterControlMode(int param_1);
bool Object_InvokeStateMethodAndRecordSuccessfulTransition(Object *object, int index);
ARM int FieldMonster_GetContactRadiusScale(unsigned char *p);
void Object3D_SubmitPositionForRemainderIndex(char *object, int a, int b);
}

// Original: arm9/main @ 0x02077788; symbol: func_02077788; size: 0x298.
// Faces a selected party member and chooses follow-state transitions using heading, radius-scaled distance, connection ownership, and the member's current state.
extern "C" void FieldMonster_ApproachPartyMemberUntilContact(unsigned char *self)
{
    Vec target, delta, closeTarget, remote, closeRemote;
    int angle;
    GameState *state = GameState::GetInstance();
    int *connection = (int *)Network_GetConnectionManager();
    char *member = (char *)state->GetPartyMemberByIndex(*(unsigned short *)(self + 0x166));
    if (!member)
        return;
    GameObject_GetConnectedMemberPosition(&remote, (Object *)member);
    target = remote;
    Vector3fix_Subtract((Vector3fix *)&target, (Vector3fix *)(self + 0x44), (Vector3fix *)&delta);
    Vector3fix_Normalize((Vector3fix *)&delta, (Vector3fix *)&delta);
    SetObjectAngleAndClearFlagC48000(self, fix32_Atan2(delta.x, delta.z));
    *(short *)(self + 0xb4) = 450;
    *(short *)(self + 0xb2) = 450;
    GameObject_ChangeMotionStateAndRefreshAnimation((Owner *)self, 1);
    int record = GameObject_GetWallContactGeometry((int)self);
    bool blocked = false;
    if (record) {
        angle = *(short *)(self + 0xae);
        if (Object_ComputeHeadingDotProduct((char *)record, &angle) < 409)
            blocked = true;
    }
    if (blocked) {
        Object_InvokeStateMethodAndRecordSuccessfulTransition((Object *)self, 1);
        *(unsigned *)(self + 0x154) = 0;
        if (Network_IsSessionActive(connection))
            Object3D_SubmitPositionForRemainderIndex((char *)self, 0, 0);
        return;
    }
    int memberIndex = *(unsigned short *)(self + 0x166);
    if (*(unsigned short *)member & 0x1000)
        memberIndex = 0;
    if (!Network_IsSessionActive(connection) || memberIndex == Network_GetLocalMemberId((char *)connection)) {
        GameObject_GetConnectedMemberPosition(&closeRemote, (Object *)member);
        closeTarget = closeRemote;
        int radius = ((Object3D *)member)->GetRadius();
        int width = ((Object3D *)self)->GetScale().x * 15;
        int multiplier = FieldMonster_GetContactRadiusScale(self) >> 1;
        int limit = (int)(((long long)multiplier * width + 2048) >> 12) + (radius >> 1);
        int distance = Vector3fix_Distance((Vector3fix *)&closeTarget, (Vector3fix *)(self + 0x44));
        if ((distance != 0 && limit > distance) || distance > 0x7800) {
            Object_InvokeStateMethodAndRecordSuccessfulTransition((Object *)self, 1);
            *(unsigned *)(self + 0x154) = 0;
            self[0x17b] = 1;
            if (Network_IsSessionActive(connection))
                Object3D_SubmitPositionForRemainderIndex((char *)self, 1, 0);
            return;
        }
    }
    if (!Network_IsSessionActive(connection) || Network_GetLocalMemberId((char *)connection) == 0) {
        if (*(unsigned char *)(member + 0xc0) == 6 || GameObject_GetEncounterControlMode((int)state->GetProtagonist()) == 2) {
            Object_InvokeStateMethodAndRecordSuccessfulTransition((Object *)self, 1);
            *(unsigned *)(self + 0x154) = 0;
            if (Network_IsSessionActive(connection) && Network_GetLocalMemberId((char *)connection) == 0)
                Object3D_SubmitPositionForRemainderIndex((char *)self, 0, 0);
        }
    }
}
