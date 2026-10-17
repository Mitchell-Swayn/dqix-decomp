#include <globaldefs.h>

#pragma force_active on
// Original: arm9/ov024 @ 0x021DE25C; symbol: func_ov024_021de25c; size: 0x18.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int TestDescriptorFlag20(unsigned char* self)
{
    return ((*(unsigned**)(self+0x138))[5] & 0x20) != 0;
}
