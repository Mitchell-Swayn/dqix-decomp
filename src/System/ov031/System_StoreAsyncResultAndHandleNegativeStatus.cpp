#include <globaldefs.h>
extern "C" void System_LockSharedMutex();
extern "C" int Network_ActivateContextUnderMutex(unsigned);
extern "C" void func_ov031_0223fa20();
extern "C" void Unclassified_ProcessObjectAndInvokeGlobalCallback(void*, unsigned);
extern "C" int data_ov031_02290dc4;
extern "C" int data_ov031_02290dbc;
// Original: arm9/ov031 @ 0x0223F188; symbol: func_ov031_0223f188; size: 0x60.
extern "C" int System_StoreAsyncResultAndHandleNegativeStatus(int* output, unsigned argument) {
    System_LockSharedMutex();
    int result = Network_ActivateContextUnderMutex(argument);
    *output = result;
    data_ov031_02290dc4 = result;
    func_ov031_0223fa20();
    if (*output >= 0) return 1;
    Unclassified_ProcessObjectAndInvokeGlobalCallback(output, argument);
    data_ov031_02290dbc = 3;
    return 0;
}
