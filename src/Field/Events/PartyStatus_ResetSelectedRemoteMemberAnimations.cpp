#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager(void);
extern "C" int Network_GetLocalMemberId(char *object);
extern "C" void *GameResources_GetInstance(void);
extern "C" void PartyStatus_ResetMappedMemberAnimation(void *records, int index);
extern "C" void PartyStatus_SetMappedMemberAnimationFlags(char *self, int enabled, unsigned char mask, int wanted);
// Original: arm9/ov017 @ 0x021C6034; symbol: func_ov017_021c6034; size: 0x70.
extern "C" void PartyStatus_ResetSelectedRemoteMemberAnimations(const signed char *flags) {
    void *connection = Network_GetConnectionManager();
    int activeIndex = Network_GetLocalMemberId((char *)connection);
    if (flags[activeIndex] == 1) return;
    char *resources = (char *)GameResources_GetInstance() + 0x3000;
    char *records = *(char **)(resources + 0x6d0);
    for (int i = 0; i < 4; ++i) {
        if (flags[i] == 1) {
            PartyStatus_ResetMappedMemberAnimation(records, i);
            PartyStatus_SetMappedMemberAnimationFlags(records, 1, 1, i);
        }
    }
}
