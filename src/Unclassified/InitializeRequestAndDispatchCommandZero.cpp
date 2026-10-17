#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int WirelessCommand_InitializeAndClearSharedHalfword16(int, int);
extern "C" void SetGlobalIndexedWordAtOffset18(int, int);
extern "C" int *ReadGlobalOperationContextPointerAt4(void);
extern "C" int func_020d40bc(int, int, int, int, int, int);

// Original: arm9/main @ 0x020D4FA4; symbol: func_020d4fa4; size: 0x60.
extern "C" int InitializeRequestAndDispatchCommandZero(int first, int second, int third, int fourth) {
    int result = WirelessCommand_InitializeAndClearSharedHalfword16(first, third);
    if (result != 0) {
        return result;
    }
    SetGlobalIndexedWordAtOffset18(0, second);
    int *context = ReadGlobalOperationContextPointerAt4();
    result = func_020d40bc(0, 4, context[0], context[1], context[4], fourth);
    if (result == 0) {
        result = 2;
    }
    return result;
}
