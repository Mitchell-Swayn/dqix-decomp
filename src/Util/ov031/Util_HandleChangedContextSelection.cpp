#include <globaldefs.h>
ARM
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void* Unclassified_InvokeHelperWithZeroFifthArgument(int,void(*)(),int,int);
extern "C" void func_ov031_0222c7d8();
struct Context { unsigned short a,selected; unsigned char *state; };
extern "C" Context data_ov031_02290c8c;
// Original: arm9/ov031 @ 0x0222CAD8; symbol: func_ov031_0222cad8; size: 0x84.
extern "C" void Util_HandleChangedContextSelection() {
    unsigned char *state = data_ov031_02290c8c.state;
    if (data_ov031_02290c8c.selected == *(unsigned short*)(state + 0x40) || state[0x51] <= 4) {
        if (state[0x59]) return;
        System_ResolveGlobalGroupEntry(9);
        data_ov031_02290c8c.state[0x59] = 1;
    } else {
        System_ResolveGlobalGroupEntry(19);
        void *operation = Unclassified_InvokeHelperWithZeroFifthArgument(0,func_ov031_0222c7d8,0,120);
        *(void**)(data_ov031_02290c8c.state + 0x38) = operation;
    }
}
