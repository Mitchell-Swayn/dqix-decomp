#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Vector.h>
#include <System/Matrix.h>
#include <Memory/AllocatorUnion.h>
ARM
#pragma always_inline on

struct Object;
struct Owner;
union Vector {
    struct {
        int x, y, z;
    };
    int v[3];
};

extern "C" {
void *Network_GetConnectionManager();
ARM bool Network_IsSessionActive(int *param_1);
int Network_GetLocalMemberId(char *p);
bool Network_IsParentOrOffline(unsigned *p);
ARM int Object_ComputeHeadingDotProduct(char *p, const int *angle);
void SetObjectAngleAndClearFlagC48000(void *object, int angle);
ARM void GameObject_ChangeMotionStateAndRefreshAnimation(Owner *object, unsigned value);
ARM int GameObject_GetWallContactGeometry(int p);
void GameObject_GetAuthorityPosition(Vector *out, unsigned char *p);
bool Object_InvokeStateMethodAndRecordSuccessfulTransition(Object *object, int index);
ARM int FieldMonster_GetContactRadiusScale(unsigned char *p);
void Object3D_SubmitPositionForRemainderIndex(char *object, int a, int b);
}

// Original: arm9/main @ 0x02077be0; symbol: func_02077be0; size: 0x2a0.
// Walks toward a stored planar retreat point, then finishes on radius contact or remaining path distance.
extern "C" void FieldMonster_MoveToRetreatTargetUntilArrival(unsigned char *self)
{
    Vector selfPos, targetPos, delta, authority, closeAuth;
    int angle;
    GameState *state = GameState::GetInstance();
    int *connection = (int *)Network_GetConnectionManager();
    char *member = (char *)state->GetPartyMemberByIndex(*(unsigned short *)(self + 0x166));
    if (!member)
        return;
    int blocked = 0;
    selfPos = *(Vector *)(self + 0x44);
    selfPos.y = blocked;
    targetPos = *(Vector *)(self + 0x158);
    targetPos.y = blocked;
    Vector3fix_Subtract((Vector3fix *)&targetPos, (Vector3fix *)&selfPos, (Vector3fix *)&delta);
    Vector3fix_Normalize((Vector3fix *)&delta, (Vector3fix *)&delta);
    SetObjectAngleAndClearFlagC48000(self, fix32_Atan2(delta.x, delta.z));
    *(short *)(self + 0xb4) = 450;
    *(short *)(self + 0xb2) = 450;
    GameObject_ChangeMotionStateAndRefreshAnimation((Owner *)self, 1);
    int record = GameObject_GetWallContactGeometry((int)self);
    if (record) {
        angle = *(short *)(self + 0xae);
        if (Object_ComputeHeadingDotProduct((char *)record, &angle) < 409)
            blocked = 1;
    }
    if (blocked) {
        Object_InvokeStateMethodAndRecordSuccessfulTransition((Object *)self, 1);
        *(unsigned *)(self + 0x154) = 0;
        if (Network_IsSessionActive(connection))
            Object3D_SubmitPositionForRemainderIndex((char *)self, 0, 0);
        return;
    }
    int pathDistance = Vector3fix_Distance((Vector3fix *)&selfPos, (Vector3fix *)&targetPos);
    int memberIndex = *(unsigned short *)(self + 0x166);
    if (*(unsigned short *)member & 0x1000)
        memberIndex = 0;
    if (!Network_IsSessionActive(connection) || memberIndex == Network_GetLocalMemberId((char *)connection)) {
        GameObject_GetAuthorityPosition(&closeAuth, (unsigned char *)member);
        authority = closeAuth;
        int radius = ((Object3D *)member)->GetRadius();
        int width = ((Object3D *)self)->GetScale().x * 15;
        int multiplier = FieldMonster_GetContactRadiusScale(self) >> 1;
        int limit = (int)(((long long)multiplier * width + 2048) >> 12) + (radius >> 1);
        int distance = Vector3fix_Distance((Vector3fix *)&authority, (Vector3fix *)(self + 0x44));
        if (distance != 0 && limit > distance) {
            Object_InvokeStateMethodAndRecordSuccessfulTransition((Object *)self, 1);
            *(unsigned *)(self + 0x154) = 0;
            self[0x17b] = 1;
            if (Network_IsSessionActive(connection))
                Object3D_SubmitPositionForRemainderIndex((char *)self, 1, 0);
            return;
        }
    }
    if (!Network_IsSessionActive(connection) || Network_GetLocalMemberId((char *)connection) == 0) {
        if (pathDistance >= 0x1800 && self[0x17b] == 0)
            return;
        Object_InvokeStateMethodAndRecordSuccessfulTransition((Object *)self, 1);
        *(unsigned *)(self + 0x154) = 0;
        if (Network_IsSessionActive(connection) && Network_IsParentOrOffline((unsigned *)connection))
            Object3D_SubmitPositionForRemainderIndex((char *)self, 0, 0);
    }
}
