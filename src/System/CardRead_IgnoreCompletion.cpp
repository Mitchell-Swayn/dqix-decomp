#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020758A0; symbol: func_020758a0; size: 0x4.
// Passed as completion callback by func_02075910 to func_020d05ec.
// The latter stores callback/context at manager +0x38/+0x3C; func_020d03fc
// invokes it with the saved context in r0 at 0x020D05D8/0x020D05DC.
extern "C" void CardRead_IgnoreCompletion(void* context)
{
}
