#include <globaldefs.h>
extern "C" {
int Quest_GetGlobalOrderState(void);
unsigned int Script_ReadParameterAsInteger(int);
int Quest_FindActiveEntryById(int, unsigned int);
void Script_WriteIntegerReferenceOutput(int, unsigned short);
// Original: arm9/main @ 0x0209D214; symbol: func_0209d214; size: 0x4C.
ARM int Script_ReadMatchingRequestHalfwordAtOffsetA(int param_1) {
    int result = Quest_GetGlobalOrderState();
    if (result == 0) return 0;
    unsigned int value = Script_ReadParameterAsInteger(param_1);
    int found = Quest_FindActiveEntryById(result, value);
    if (found == 0) return 0;
    Script_WriteIntegerReferenceOutput(param_1 + 8, *(unsigned short *)(found + 10));
    return 1;
}
}
