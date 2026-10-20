#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char *p);
extern "C" void Network_MarkMemberDisconnected(char *p, int value);
// Original: arm9/ov017 @ 0x021CEA64; symbol: func_ov017_021cea64; size: 0x28.
extern "C" void GameState_SetResolvedSlotWhenIndexedValueChanges(int a0, char *object, int a2, int a3, char *p) {
    int value = *(int *)(object + 4);
    if (value != Network_GetLocalMemberId(p))
        Network_MarkMemberDisconnected(p, value);
}
