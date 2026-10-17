#include <globaldefs.h>
ARM
extern "C" char* ResolveOverrideOrIndexedRecord(char*);
extern "C" int IsOneOfFourOverlayCodes(int);
extern "C" void* ReadGlobalAt02108E10();
extern "C" ARM char* TryTransformFirstOrSecondEmbeddedRecord(char*, void*);
// Original: arm9/ov000 @ 0x021627FC; symbol: func_ov000_021627fc; size: 0x68.
extern "C" int Overlay_TestResolvedRecordTransformState(char *p) {
    char *record = ResolveOverrideOrIndexedRecord(p);
    if (!record) return 0;
    unsigned short id = *(unsigned short *)record;
    int selector = id;
    if (IsOneOfFourOverlayCodes(selector)) selector = 1;
    char *result = TryTransformFirstOrSecondEmbeddedRecord((char *)ReadGlobalAt02108E10(), (void *)(short)selector);
    if (!result) return 0;
    unsigned state = *(unsigned *)(result + 0x14) >> 28;
    if (state == 5) return 1;
    if (state == 2) return 1;
    return 0;
}
