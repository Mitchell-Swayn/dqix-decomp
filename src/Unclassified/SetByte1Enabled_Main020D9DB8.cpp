#include <globaldefs.h>
// func_020d9db8: 0x020d9db8–0x020d9dc4, arm; 12 bytes
// Original: arm9/main @ 0x020D9DB8; symbol: func_020d9db8; size: 0xC.
extern "C" void SetByte1Enabled_Main020D9DB8(int self) {
    *(unsigned char*)(self + 1) = 1;
}
