#include <globaldefs.h>
ARM
extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);
// Original: arm9/main @ 0x02068200; symbol: func_02068200; size: 0x38.
extern "C" int Text_ParseIntegerFromFirstDecimalDigit(const signed char* p) { for(;*p;p++)if(*p>=48 && *p<=57)return Runtime_ParseStringAsBaseTenInteger((const char*)p);return 0; }
