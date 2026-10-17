#include <globaldefs.h>
ARM
extern "C" int ReadIndexedSignedField1038(char *p);
extern "C" void SetResolvedSlotBitAt100E(char *p, int value);
// Original: arm9/ov017 @ 0x021CEA64; symbol: func_ov017_021cea64; size: 0x28.
extern "C" void GameState_SetResolvedSlotWhenIndexedValueChanges(int a0, char *object, int a2, int a3, char *p) {
    int value = *(int *)(object + 4);
    if (value != ReadIndexedSignedField1038(p))
        SetResolvedSlotBitAt100E(p, value);
}
