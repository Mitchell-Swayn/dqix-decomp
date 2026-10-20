#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>

extern "C" {
void* Network_GetConnectionManager(void*);
int Network_IsSessionActive(void*);
int Network_GetLocalMemberId(void*);
void GameObject_GetAuthorityPosition(Vector3fix*, void*);
void SetObjectAngleAndClearFlagC48000(void*, int);
void GameObject_ChangeMotionStateAndRefreshAnimation(void*, int);
int fix32_Atan2(int, int);
void Vector3fixMultiplyScalar(const Vector3fix*, int, Vector3fix*);
void Vector3fix_Add(const Vector3fix*, const Vector3fix*, Vector3fix*);
void Network_QueueObjectDirectionAndPosition(unsigned, int, int, Vector3fix, int, int, unsigned short);
}

// Original: arm9/main @ 0x020781E8; symbol: func_020781e8; size: 0x1B0.
extern "C" ARM int World_UpdateObjectDirectionFromPartyMember(Object3D* self)
{
    GameState* game = GameState::GetInstance();
    GameObject* member = game->GetPartyMemberByIndex(*(unsigned short*)((char*)self + 0x166));
    if (member == 0)
        return 0;

    int angle = 0;
    void* context = Network_GetConnectionManager(member);
    if (!Network_IsSessionActive(context) || !Network_GetLocalMemberId(context)) {
        Vector3fix destination;
        Vector3fix delta;
        Vector3fix memberPosition;
        GameObject_GetAuthorityPosition(&memberPosition, member);
        struct PlainVector { int words[3]; };
        *(PlainVector*)&destination = *(PlainVector*)&memberPosition;
        Vector3fix_Subtract(&destination, (Vector3fix*)((char*)self + 0x44), &delta);
        Vector3fix_Normalize(&delta, &delta);
        delta.y = -delta.y;
        delta.x = -delta.x;
        delta.z = -delta.z;
        angle = fix32_Atan2(delta.x, delta.z);
        SetObjectAngleAndClearFlagC48000(self, angle);
        delta.y = 0;
        Vector3fixMultiplyScalar(&delta, 0x5000, &delta);
        Vector3fix_Add((Vector3fix*)((char*)self + 0x44), &delta,
                       (Vector3fix*)((char*)self + 0x158));
    }

    *(unsigned short*)((char*)self + 0xb4) = 0x1c2;
    *(unsigned short*)((char*)self + 0xb2) = 0x1c2;
    GameObject_ChangeMotionStateAndRefreshAnimation(self, 1);
    self->DisableFlag(0x80);
    *((unsigned char*)self + 0x17a) = 0;

    if (Network_IsSessionActive(context) && !Network_GetLocalMemberId(context)) {
        unsigned field = self->GetField06();
        short variant = *(short*)((char*)self + 2);
        Vector3fix* position = (Vector3fix*)((char*)self + 0x158);
        int remainder = (*(short*)((char*)self + 4) - 0x70) % 12;
        if (remainder >= 0 && remainder < 12)
            Network_QueueObjectDirectionAndPosition(field, remainder, variant, *position, angle, 7,
                                *(unsigned short*)((char*)self + 0x166));
    }
    return 1;
}
