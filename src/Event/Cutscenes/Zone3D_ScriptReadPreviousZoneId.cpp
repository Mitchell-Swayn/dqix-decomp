#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x0215F324; symbol: func_ov001_0215f324; size: 0x20.
extern "C" int Zone3D_ScriptReadPreviousZoneId(void *p) {
    unsigned int value = *(unsigned short *)((unsigned char *)Zone3D_GetMainInstance() + 2);
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
