#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" int ReadScriptParameterAsInteger(void *);
// Original: arm9/ov001 @ 0x02161F3C; symbol: func_ov001_02161f3c; size: 0x28.
extern "C" int StoreScriptIntegerAtGlobalOffset2750AndReturnOne(void *parameter) {
    void *base = ReadGlobalValueAt020FB3F0();
    int value = ReadScriptParameterAsInteger(parameter);
    *(int *)((char *)base + 0x2750) = value;
    return 1;
}
