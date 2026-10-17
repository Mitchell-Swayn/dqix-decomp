#include <globaldefs.h>
ARM
extern "C" void Ov031_DecrementBlockedContextCount(void *);
extern "C" unsigned int data_ov031_0224e54c;
// Original: arm9/ov031 @ 0x0220F2CC; symbol: func_ov031_0220f2cc; size: 0x14.
extern "C" void func_ov031_0220f2cc(void) { Ov031_DecrementBlockedContextCount(&data_ov031_0224e54c); }
