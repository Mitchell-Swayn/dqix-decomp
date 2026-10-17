#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" char* strcpy(char*,const char*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);extern "C" char* data_02108740[2];
// Original: arm9/main @ 0x0205E084; symbol: func_0205e084; size: 0x2C.
extern "C" int Script_CopyGlobalStringAt1A(const void* p){const char* s=_ZNK6Script9Parameter8ToStringEv(p);if(s)strcpy(data_02108740[1]+26,s);return 1;}
