#include <globaldefs.h>
// func_020dbd90: 0x020dbd90–0x020dbd9c, arm; 12 bytes
// Original: arm9/main @ 0x020DBD90; symbol: func_020dbd90; size: 0xC.
extern "C" void NetworkTransfer_MarkSaveDataSendComplete(int self) {
    *(unsigned char*)(self + 1) = 1;
}
