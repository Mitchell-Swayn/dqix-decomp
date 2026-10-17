#include <globaldefs.h>
extern "C" {
int Object_GetGlobalRequestQueue(void);
unsigned int ReadScriptParameterAsInteger(int);
int Object_FindBoundedIdEntryThrough204(int, unsigned int);
void SetNestedSecondWordForTypeThree(int, unsigned short);
// Original: arm9/main @ 0x0209D214; symbol: func_0209d214; size: 0x4C.
ARM int Script_ReadMatchingRequestHalfwordAtOffsetA(int param_1) {
    int result = Object_GetGlobalRequestQueue();
    if (result == 0) return 0;
    unsigned int value = ReadScriptParameterAsInteger(param_1);
    int found = Object_FindBoundedIdEntryThrough204(result, value);
    if (found == 0) return 0;
    SetNestedSecondWordForTypeThree(param_1 + 8, *(unsigned short *)(found + 10));
    return 1;
}
}
