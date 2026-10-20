#include <globaldefs.h>
ARM
extern "C" unsigned long long StaffRoll_GetElapsedMilliseconds(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02163228; symbol: func_ov001_02163228; size: 0x20.
extern "C" int Script_ReadCanvasElapsedTime(void *p) {
    unsigned int value = (unsigned int)StaffRoll_GetElapsedMilliseconds();
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
