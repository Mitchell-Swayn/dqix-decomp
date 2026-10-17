#include <globaldefs.h>
ARM

extern "C" unsigned char *FindIndexedGameStateObjectWithFlag400(void *, int);

// Original: arm9/ov024 @ 0x021F5300; symbol: func_ov024_021f5300; size: 0x44.
extern "C" int GameState_WriteValueForEligibleIndexedObject(void **stateRef, short value, int index, int *success, short *outValue) {
    unsigned char *object = FindIndexedGameStateObjectWithFlag400(*stateRef, value);
    if (object == 0) {
        return 0;
    }
    unsigned char mode = *(unsigned char *)((char *)*(void **)(object + 0x138) + 0x24);
    if (mode >= 3) {
        return 0;
    }
    *success = 1;
    *outValue = value;
    return 1;
}
