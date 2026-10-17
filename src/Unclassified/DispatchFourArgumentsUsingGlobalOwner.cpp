#include <globaldefs.h>
extern "C" { extern char data_0214e4c8[]; void WriteDisplayFlagsAndRefreshProtectedState(void*,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020DAF9C; symbol: func_020daf9c; size: 0x38.
 void DispatchFourArgumentsUsingGlobalOwner(unsigned a,unsigned b,unsigned c,unsigned d) { WriteDisplayFlagsAndRefreshProtectedState(data_0214e4c8,a,b,c,d); } }
