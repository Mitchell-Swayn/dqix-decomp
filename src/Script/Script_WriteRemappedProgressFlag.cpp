#include <globaldefs.h>
extern "C" int GameState_GetSerializedProgressState(void); extern "C" unsigned int Script_ReadParameterAsInteger(int);
extern "C" unsigned int Script_GetRemappedProgressFlagMask(int, unsigned int); extern "C" void Script_WriteIntegerReferenceOutput(int, unsigned int);
ARM
// Original: arm9/main @ 0x0209D4D0; symbol: func_0209d4d0; size: 0x40.
extern "C" int Script_WriteRemappedProgressFlag(int p) {
    int context=GameState_GetSerializedProgressState(); if (!context) return 0;
    unsigned int item=Script_ReadParameterAsInteger(p); item=Script_GetRemappedProgressFlagMask(context,item);
    Script_WriteIntegerReferenceOutput(p+8,item); return 1;
}
