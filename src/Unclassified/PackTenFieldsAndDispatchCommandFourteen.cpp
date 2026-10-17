#include <globaldefs.h>
extern "C" void AcquireCommandEntryAndStoreFiveValues(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D2038; symbol: func_020d2038; size: 0x4C.
extern "C" ARM void PackTenFieldsAndDispatchCommandFourteen(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,unsigned f,unsigned g,unsigned h,unsigned i,unsigned j){AcquireCommandEntryAndStoreFiveValues(14,a|(i<<16),c,((g<<24)|(h<<22))|f,((d<<26)|(b<<24)|(j<<16))|e);}
