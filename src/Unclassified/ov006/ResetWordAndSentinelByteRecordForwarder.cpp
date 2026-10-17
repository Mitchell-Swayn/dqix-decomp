#include <globaldefs.h>
ARM
extern "C" void ResetWordAndSentinelByteRecord(char* p);
// Original: arm9/ov006 @ 0x02153730; symbol: func_ov006_02153730; size: 0xC.
extern "C" void ResetWordAndSentinelByteRecordForwarder(char* p)
{
    ResetWordAndSentinelByteRecord(p);
}
