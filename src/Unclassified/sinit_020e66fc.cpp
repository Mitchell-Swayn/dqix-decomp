#include <globaldefs.h>
extern "C" {
extern unsigned char data_0214e34c[];
void Clear336ByteRecordAndPackedFlagsAndReturnPointer(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E66FC; symbol: __sinit_020e66fc; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e66fc()
{
    Clear336ByteRecordAndPackedFlagsAndReturnPointer(data_0214e34c);
}
