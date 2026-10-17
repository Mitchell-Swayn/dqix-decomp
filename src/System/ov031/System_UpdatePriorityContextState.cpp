#include <globaldefs.h>
ARM
extern "C" void _Z28CycleCurrentPriorityContextsv(void);
extern "C" void func_ov031_02201f84(void* p, unsigned value);
extern "C" void func_ov031_02201f98(void* object, unsigned value);
// Original: arm9/ov031 @ 0x02203398; symbol: func_ov031_02203398; size: 0x50.
extern "C" void System_UpdatePriorityContextState(void* object) {
    _Z28CycleCurrentPriorityContextsv();
    unsigned char state = *((unsigned char*)object + 8);
    if ((((unsigned)state + 0xfd) & 0xff) <= 1) {
        func_ov031_02201f98(object, 0x19);
        *((unsigned char*)object + 8) = 7;
    } else if (state != 0) {
        func_ov031_02201f84(object, 0x1a);
    }
}
