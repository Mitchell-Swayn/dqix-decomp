#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" void *ReadGlobalValueAt02108844(void);

// Original: arm9/ov001 @ 0x021609E4; symbol: func_ov001_021609e4; size: 0x1C.
extern "C" int Unclassified_SetScriptParameterByte490(void *parameter) {
    int value = ReadScriptParameterAsInteger(parameter);
    unsigned char *global = (unsigned char *)ReadGlobalValueAt02108844();
    global[0x490] = (unsigned char)value;
    return 1;
}
