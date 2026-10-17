#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(int);extern "C" void FilterSixtyFourByteRecordsWithEitherByteFlag(void*,int);
// Original: arm9/main @ 0x0209D688; symbol: func_0209d688; size: 0x34.
extern "C" ARM int Script_FilterRecordsWithEitherByte25Or26(int a){void* p=ReadWordAtOffset0();if(!p)return 0;FilterSixtyFourByteRecordsWithEitherByteFlag(p,ReadScriptParameterAsInteger(a));return 1;}
