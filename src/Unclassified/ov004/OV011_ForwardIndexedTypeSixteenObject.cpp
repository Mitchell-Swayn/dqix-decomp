#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void Ov023_ForwardObjectAt20(void*, int);
// Original: arm9/ov004 @ 0x021556DC; symbol: func_ov004_021556dc; size: 0x40.
extern "C" int OV011_ForwardIndexedTypeSixteenObject(void *self) {
    void *context = func_ov011_021849c8(self);
    void *object = func_ov023_021f6880(context, 0x2e);
    if (!object) return 0;
    if (OV023_ReadHalfwordField04(object) != 0x10) return 0;
    Ov023_ForwardObjectAt20(object, -1);
    return 0;
}
