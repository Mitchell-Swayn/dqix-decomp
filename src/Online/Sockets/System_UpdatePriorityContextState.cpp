#include <globaldefs.h>
ARM
extern "C" void _Z28CycleCurrentPriorityContextsv(void);
extern "C" void Network_SendTcpAcknowledgment(void* p, unsigned value);
extern "C" void Network_SendTcpFinishAcknowledgment(void* object, unsigned value);
// Original: arm9/ov031 @ 0x02203398; symbol: func_ov031_02203398; size: 0x50.
extern "C" void System_UpdatePriorityContextState(void* object) {
    _Z28CycleCurrentPriorityContextsv();
    unsigned char state = *((unsigned char*)object + 8);
    if ((((unsigned)state + 0xfd) & 0xff) <= 1) {
        Network_SendTcpFinishAcknowledgment(object, 0x19);
        *((unsigned char*)object + 8) = 7;
    } else if (state != 0) {
        Network_SendTcpAcknowledgment(object, 0x1a);
    }
}
