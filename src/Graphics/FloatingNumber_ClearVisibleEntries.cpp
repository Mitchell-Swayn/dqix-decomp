#include <globaldefs.h>
ARM
extern "C" void FloatingNumber_ResetEntry(void*);
// Original: arm9/main @ 0x0203A588; symbol: func_0203a588; size: 0x48.
extern "C" void FloatingNumber_ClearVisibleEntries(unsigned char* p){for(int i=0;i<16;++i){int offset=i*24;if(*(signed char*)(p+offset+0x555)<35)FloatingNumber_ResetEntry(p+0x550+offset);}}
