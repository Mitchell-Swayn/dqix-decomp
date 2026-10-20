#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA978; symbol: func_ov023_021ea978; size: 0x38.
extern "C" int SetNestedWordToRoundedGlobalValue(void *obj) {
    int value = *(short *)Zone3D_GetMainInstance();
    int rounded = value - value % 100;
    Script_WriteIntegerReferenceOutput(obj, (short)rounded);
    return 1;
}
