#include <globaldefs.h>
ARM
extern "C" void Script_ClearExecutionStatusAndArchive(void*);
// Original: arm9/ov017 @ 0x021D49D0; symbol: func_ov017_021d49d0; size: 0x54.
extern "C" void* Script_ResetInterpreterContext(char* p) {
    *(unsigned int*)(p + 0x14) = *(unsigned int*)(p + 0x10);
    *(unsigned int*)(p + 0x18) = *(unsigned int*)(p + 0x10);
    *(unsigned int*)(p + 0x28) = *(unsigned int*)(p + 0x24);
    *(unsigned int*)(p + 0x2c) = *(unsigned int*)(p + 0x24);
    *(unsigned int*)(p + 0x38) = 0;
    *(unsigned int*)(p + 4) = 0;
    *(unsigned int*)(p + 0xc) = 0;
    *(unsigned int*)(p + 0x20) = 0;
    *(unsigned int*)(p + 0x40) = 0;
    *(unsigned int*)p = 1;
    Script_ClearExecutionStatusAndArchive(p);
    return p;
}
