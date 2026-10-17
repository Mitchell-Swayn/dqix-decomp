#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
// Original: arm9/ov004 @ 0x02156ED0; symbol: func_ov004_02156ed0; size: 0x34.
extern "C" void* OV011_GetObjectIfFieldValueSeven(void *self, unsigned index) {
    void *context = func_ov011_021849c8(self);
    void *result = func_ov023_021f6880(context, index);
    if (!result) return 0;
    if (OV023_ReadHalfwordField04(result) != 7) result = 0;
    return result;
}
