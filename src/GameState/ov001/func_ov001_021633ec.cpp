#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt02108844();
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" int Object_ReadFlagWithHighIdentifierRemapping(char *, int);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x021633EC; symbol: func_ov001_021633ec; size: 0x4C.
extern "C" int func_ov001_021633ec(void *parameter) {
    int value = Object_ReadFlagWithHighIdentifierRemapping((char *)ReadGlobalValueAt02108844(), ReadScriptParameterAsInteger(parameter));
    if (value) SetNestedSecondWordForTypeThree((char *)parameter + 8, 1);
    else SetNestedSecondWordForTypeThree((char *)parameter + 8, 0);
    return 1;
}
