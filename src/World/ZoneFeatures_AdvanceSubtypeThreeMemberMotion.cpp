#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct Flags { unsigned char low : 2; unsigned char rest : 6; };
struct Object {
    unsigned char pad[0xc1];
    Flags flags;
    unsigned char pad2[0x190];
    unsigned char a, b;
};
struct Vec {
    int x, y, z;
};

extern "C" {
void *GameState_GetIndexList(GameState *state);
int GameObject_GetFollowPredecessorMember(int param_1);
void GameObject_RequestMovementInputEnable(int param_1);
void Object3D_SetNormalizedAngleAndUpdatePosition(char *object, int value);
void GameObject_DisableMovementInput(Object *p, int reset);
void Network_QueuePartyPositionUpdate(unsigned char a, unsigned int b, unsigned int c, unsigned int d, unsigned char e);
void Network_QueuePartyVisualStateUpdate(unsigned char a, unsigned char b, unsigned char c);
void *SystemState_GetGlobalFlags();
void SystemState_ClearFlags(unsigned int *word, unsigned int mask);
}

// Original: arm9/main @ 0x020A8D08; symbol: func_020a8d08; size: 0x178.
// Advances subtype-3 party-member motion; on completion copies the leader pose and queues network updates.
extern "C" void ZoneFeatures_AdvanceSubtypeThreeMemberMotion(unsigned char *self, unsigned char index)
{
    GameState *state = GameState::GetInstance();
    char *member = (char *)state->GetPartyMemberByIndex(index);
    char *leader = (char *)state->GetUnknownGameObject();
    GameState_GetIndexList(state);
    state->GetPartyMemberByIndex(GameObject_GetFollowPredecessorMember((int)member));
    if ((self[4] & (1 << index)) && !(self[5] & (1 << index))) {
        Vector3i position;
        position = *(Vector3i *)(member + 0x44);
        position.x += *(int *)(self + 0x10);
        position.z += *(int *)(self + 0x14);
        *(Vector3i *)(member + 0x44) = position;
        if (*(short *)(member + 0xac) == 0) {
            *(unsigned char *)(member + 0xc1) = *(unsigned char *)(member + 0xc1) & ~8;
            GameObject_RequestMovementInputEnable((int)member);
            self[5] |= 1 << index;
            if (*(short *)(member + 4) != *(short *)(leader + 4))
                *(Vector3i *)(member + 0x44) = *(Vector3i *)(leader + 0x44);
            Vec update = *(Vec *)(member + 0x44);
            Network_QueuePartyPositionUpdate(index, update.x, update.y, update.z, 0);
            Network_QueuePartyVisualStateUpdate(index, 0x1f, 0);
            SystemState_ClearFlags((unsigned int *)SystemState_GetGlobalFlags(), 0x402);
        } else {
            Object3D_SetNormalizedAngleAndUpdatePosition(member, *(short *)(member + 0xae) + *(int *)(self + 8));
            if (*(short *)(member + 4) == *(short *)(leader + 4))
                *(int *)(self + 8) -= 0x28;
            GameObject_DisableMovementInput((Object *)member, 1);
        }
    }
}
