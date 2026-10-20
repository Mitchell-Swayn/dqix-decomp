#include <globaldefs.h>
ARM
extern "C" char *_ZN15LightingManager11GetInstanceEv(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02161CE8; symbol: func_ov001_02161ce8; size: 0x20.
extern "C" int SetOutputNestedSecondWordFromLightingManager(void *output) {
    char *lighting = _ZN15LightingManager11GetInstanceEv();
    Script_WriteIntegerReferenceOutput(output, *(int *)(lighting + 0x98));
    return 1;
}
