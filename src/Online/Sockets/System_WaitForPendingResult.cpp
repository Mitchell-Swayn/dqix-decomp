#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
struct BlockedContextList;
extern "C" void _Z19BlockCurrentContextP18BlockedContextList(BlockedContextList*);
extern "C" void _Z28CycleCurrentPriorityContextsv();
// Original: arm9/ov031 @ 0x02203500; symbol: func_ov031_02203500; size: 0x7C.
extern "C" unsigned System_WaitForPendingResult(unsigned* output, char* request) {
    if (*(unsigned*)(request+0x44)==0 && *(unsigned char*)(request+8)==4) {
        int irq = _Z20DisableIRQInterruptsv();
        while (*(unsigned*)(request+0x44)==0 && *(unsigned char*)(request+8)==4) {
            *(unsigned*)(request+4)=2;
            _Z19BlockCurrentContextP18BlockedContextList(0);
        }
        _Z20SetIRQInterruptStatei(irq);
    } else {
        _Z28CycleCurrentPriorityContextsv();
    }
    *output=*(unsigned*)(request+0x44);
    return *output ? *(unsigned*)(request+0x40) : 0;
}
