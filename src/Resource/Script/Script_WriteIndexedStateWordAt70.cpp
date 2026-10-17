#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int ReadWordAtOffset0(void);
extern "C" int ReadScriptParameterAsInteger(int);
// Original: arm9/main @ 0x0209D770; symbol: func_0209d770; size: 0x3C.
extern "C" int Script_WriteIndexedStateWordAt70(int param) {
    int object = ReadWordAtOffset0();
    if (object == 0) {
        return 0;
    }
    int first = ReadScriptParameterAsInteger(param);
    int second = ReadScriptParameterAsInteger(param + 8);
    *(int *)(object + first * 4 + 0x70) = second;
    return 1;
}
