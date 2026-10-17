#include <globaldefs.h>
ARM

extern "C" volatile unsigned short data_02111668;
extern "C" void func_01ff8300(void);
extern "C" void func_01ff8218(void);

// Original: arm9/itcm @ 0x01FF81E4; symbol: func_01ff81e4; size: 0x34.
extern "C" void System_WaitForHardwareHalfwordAndClear(void) {
    while (data_02111668 == 0) {
    }
    *(volatile unsigned short *)0x04000208 = 0;
    func_01ff8300();
    func_01ff8218();
}
