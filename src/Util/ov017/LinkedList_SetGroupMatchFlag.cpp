#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt02108844(void);
// Original: arm9/ov017 @ 0x02198F70; symbol: func_ov017_02198f70; size: 0x14.
extern "C" void LinkedList_SetGroupMatchFlag(void *, unsigned char value) {
    *(unsigned char *)((char *)ReadGlobalValueAt02108844() + 0x491) = value;
}
