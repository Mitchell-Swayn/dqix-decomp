#include <globaldefs.h>
extern "C" int ReadSharedObjectSignedByte1B();
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void CreateSharedDisplayResource();
extern "C" void SetMainLoopCallback(void (*)());
extern "C" unsigned char* volatile data_ov031_02290c94;
extern "C" void System_DispatchSelectedSharedCallback();
// Original: arm9/ov031 @ 0x0222D418; symbol: func_ov031_0222d418; size: 0x5C.
extern "C" void System_DispatchSharedByteStateAndInstallCallback() {
    data_ov031_02290c94[0x2a] = (unsigned char)ReadSharedObjectSignedByte1B();
    unsigned char state = data_ov031_02290c94[0x2a];
    switch (state) {
    case 0: System_ResolveGlobalGroupEntry(7); break;
    case 1: System_ResolveGlobalGroupEntry(0xe); break;
    default: return;
    }
    CreateSharedDisplayResource();
    SetMainLoopCallback(System_DispatchSelectedSharedCallback);
}
