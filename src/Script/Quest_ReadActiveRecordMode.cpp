#include <globaldefs.h>
extern "C" unsigned* Quest_FindActiveEntryById(void*,unsigned);
// Original: arm9/main @ 0x0209618C; symbol: func_0209618c; size: 0x24.
extern "C" unsigned char Quest_ReadActiveRecordMode(void* a,unsigned b) {unsigned* p=Quest_FindActiveEntryById(a,b);if(p)return (unsigned char)((*p<<18)>>29);return 0;}
