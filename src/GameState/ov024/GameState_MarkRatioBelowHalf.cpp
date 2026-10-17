#include <globaldefs.h>
ARM
extern "C" void *FindIndexedGameStateObjectWithFlag400(void *, int);
extern "C" float ComputeRecordHalfwordRatioOrZero(unsigned char *);
extern "C" int _fgeq(float, float);
// Original: arm9/ov024 @ 0x021F3688; symbol: func_ov024_021f3688; size: 0x44.
extern "C" int GameState_MarkRatioBelowHalf(void **owner, short value, void *unused, int *outFlag, short *outValue) {
    void *object = FindIndexedGameStateObjectWithFlag400(*owner, value);
    if (!object) return 0;
    float ratio = ComputeRecordHalfwordRatioOrZero((unsigned char *)object);
    if (_fgeq(ratio, 0.5f)) return 0;
    *outFlag = 1;
    *outValue = value;
    return 1;
}
