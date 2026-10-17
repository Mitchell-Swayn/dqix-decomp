#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e22c[];
extern "C" void UnlinkNodeFromChain(void *, void *);
// Original: arm9/ov031 @ 0x02207108; symbol: func_ov031_02207108; size: 0x18.
extern "C" void System_AppendCallbackToGlobalList(void *callback) {
    UnlinkNodeFromChain((void *)data_ov031_0224e22c, callback);
}
