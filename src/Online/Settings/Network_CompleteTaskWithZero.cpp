#include <globaldefs.h>
ARM
struct NitroHandle;
void NitroHandle_OnTaskCompletion(NitroHandle *handle, int result);
// Original: arm9/ov031 @ 0x0223B604; symbol: func_ov031_0223b604; size: 0x10.
extern "C" void Network_CompleteTaskWithZero(NitroHandle *handle) {
    NitroHandle_OnTaskCompletion(handle, 0);
}
