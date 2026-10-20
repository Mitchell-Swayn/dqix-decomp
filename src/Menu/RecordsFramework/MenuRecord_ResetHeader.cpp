#include <globaldefs.h>

// Original: arm9/ov023 @ 0x021F6ED8; symbol: func_ov023_021f6ed8; size: 0x30.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void MenuRecord_ResetHeader(char* p)
{
    *(unsigned short*)(p+4)=0xffff;
    *(short*)(p+6)=0;
    *(short*)(p+8)=0;
    *(int*)(p+0x10)=0;
    *(int*)(p+0x14)=0;
    *(int*)(p+0x18)=0;
    p[0xc]=0;
    *(int*)(p+0x1c)=0;
}
