#include <globaldefs.h>
extern "C" void AcquireCommandEntryAndStoreFiveValues(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D212C; symbol: func_020d212c; size: 0x28.
extern "C" ARM void DispatchCommandSixWithFourValues(unsigned a,unsigned b,unsigned c,unsigned d){AcquireCommandEntryAndStoreFiveValues(6,a,b,c,d);}
