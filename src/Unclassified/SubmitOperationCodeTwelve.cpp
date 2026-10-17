#include <globaldefs.h>
extern "C" void AcquireCommandEntryAndStoreFiveValues(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1EE4; symbol: func_020d1ee4; size: 0x28.
extern "C" ARM void SubmitOperationCodeTwelve(unsigned a,unsigned b,unsigned c,unsigned d){AcquireCommandEntryAndStoreFiveValues(12,a,b,c,d);}
