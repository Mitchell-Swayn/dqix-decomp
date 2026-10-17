#include <globaldefs.h>
extern "C" char data_020e91c8[];extern "C" void Object_SetSixResourceFieldsAndFlag(unsigned,unsigned,unsigned,unsigned,unsigned,void*,unsigned);
// Original: arm9/main @ 0x020B1E94; symbol: func_020b1e94; size: 0x2C.
extern "C" ARM void DispatchFiveValuesUsingGlobalConfigurationTable(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e){Object_SetSixResourceFieldsAndFlag(a,b,c,d,e,data_020e91c8,c);}
