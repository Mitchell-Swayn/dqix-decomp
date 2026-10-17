#include <globaldefs.h>

extern "C" void func_0206e164(void*, int, unsigned, unsigned);

// Original: arm9/main @ 0x0206E100; symbol: func_0206e100; size: 0x20.
extern "C" ARM void InvokeBoundedIndexWithModeThree(void* owner, int index, unsigned unused, unsigned context) {
    if(index>=204) return;
    if(index<0) return;
    func_0206e164(owner, index, 3, context);
}
