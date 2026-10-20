#include <globaldefs.h>
ARM
extern "C" void OnlineMemory_FreeTagged(int, int, int);
// Original: arm9/ov031 @ 0x022127A8; symbol: func_ov031_022127a8; size: 0x18.
extern "C" void DownloadService_Free(int a0) {
    OnlineMemory_FreeTagged(6, a0, 0);
}
