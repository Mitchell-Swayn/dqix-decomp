#include <globaldefs.h>
THUMB
extern "C" {
ARM int _Z20DisableIRQInterruptsv(void);
ARM int _Z20SetIRQInterruptStatei(int state);
}
THUMB
extern "C" unsigned char data_ov031_0224f670[];
extern "C" unsigned data_ov031_0224f6f4[];
// Original: arm9/ov031 @ 0x0221FA20; symbol: func_ov031_0221fa20; size: 0x38.
extern "C" unsigned Resource_PopSharedRingQueue(void) {
    int irq = _Z20DisableIRQInterruptsv();
    volatile unsigned char *state = data_ov031_0224f670;
    int tail = *(volatile int *)(state + 0x6c);
    int head = *(volatile int *)(state + 0x68);
    unsigned value;
    if (head == tail) {
        value = 0;
    } else {
        value = data_ov031_0224f6f4[(unsigned)tail];
        int next = tail + 1;
        *(volatile unsigned *)(state + 0x6c) = next;
        if (next >= 4) {
            next = 0;
            *(volatile unsigned *)(state + 0x6c) = next;
        }
    }
    _Z20SetIRQInterruptStatei(irq);
    return value;
}
