#include <globaldefs.h>
extern "C" unsigned char data_ov031_0224e230[];
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void func_ov031_02206a68();
// Original: arm9/ov031 @ 0x02206C08; symbol: func_ov031_02206c08; size: 0x3C.
extern "C" void OV031_WaitForGlobalQueueToDrain(void) {
    int irq = _Z20DisableIRQInterruptsv();
    if (*(unsigned *)data_ov031_0224e230) {
        do { func_ov031_02206a68(); }
        while (*(unsigned *)data_ov031_0224e230);
    }
    _Z20SetIRQInterruptStatei(irq);
}
