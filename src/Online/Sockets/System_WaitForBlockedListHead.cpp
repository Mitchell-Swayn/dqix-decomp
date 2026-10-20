#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void _Z19BlockCurrentContextP18BlockedContextList(void*);
// Original: arm9/ov031 @ 0x022034AC; symbol: func_ov031_022034ac; size: 0x54.
extern "C" unsigned System_WaitForBlockedListHead(void** output, unsigned char* list) {
    void* item;
    int irq;
    irq = _Z20DisableIRQInterruptsv();
    item = *(void**)(list + 0x44);
    if (!item) {
        do {
            *(unsigned*)(list + 4) = 3;
            _Z19BlockCurrentContextP18BlockedContextList(0);
            item = *(void**)(list + 0x44);
        } while (!item);
    }
    _Z20SetIRQInterruptStatei(irq);
    *output = item;
    return *(unsigned*)(list + 0x40);
}
