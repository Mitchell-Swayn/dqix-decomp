#include <globaldefs.h>
extern "C" void* memcpy(void*, const void*, unsigned int);
// Copies the supplied byte count to offset 0x124 and stores the count at 0x128.
// Original: arm9/ov023 @ 0x021D9988; symbol: func_ov023_021d9988; size: 0x1C.
extern "C" void PartyGrowthPanel_SetMemberOrder(void* self, const void* source, unsigned int length) { memcpy((char*)self + 0x124, source, length); *((unsigned char*)self + 0x128) = (unsigned char)length; }
