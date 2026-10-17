#include <globaldefs.h>
// Original: arm9/ov024 @ 0x021DF6EC; symbol: func_ov024_021df6ec; size: 0x18.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM int TestRecordFlags14Mask40(void* object)
{
    unsigned char* record = *(unsigned char**)((unsigned char*)object + 0x138);
    return (*(unsigned int*)(record + 0x14) & 0x40) != 0;
}
