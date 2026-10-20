#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" int Script_ReadParameterAsInteger(void *);
// Original: arm9/ov001 @ 0x02161D2C; symbol: Script_StoreIntegerAtGlobalOffset274C; size: 0x28.
// Reads a script integer and stores it at offset 0x274C from the global object.
extern "C" int Zone3D_ScriptSetUnknownTransitionOptionAt274C(void *parameter) {
    unsigned char *global = (unsigned char *)Zone3D_GetMainInstance();
    int value = Script_ReadParameterAsInteger(parameter);
    *(int *)(global + 0x274c) = value;
    return 1;
}
