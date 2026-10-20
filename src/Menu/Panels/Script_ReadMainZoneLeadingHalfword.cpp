#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA958; symbol: func_ov023_021ea958; size: 0x20.
extern "C" int Script_ReadMainZoneLeadingHalfword(void *p) {
    unsigned int value = *(unsigned short *)Zone3D_GetMainInstance();
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
