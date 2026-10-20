#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4A24; symbol: func_ov017_021d4a24; size: 0x14.
extern "C" void Script_ClearExecutionStatusAndArchive(void *object) {
    *(unsigned int *)((char *)object + 0x3c) = 0;
    *(unsigned int *)((char *)object + 0x40) = 0;
    *(unsigned int *)((char *)object + 0x44) = 0;
}
