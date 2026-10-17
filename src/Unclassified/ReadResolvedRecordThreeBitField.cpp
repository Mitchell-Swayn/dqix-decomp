#include <globaldefs.h>
extern "C" unsigned* Object_FindBoundedIdEntryThrough204(void*,unsigned);
// Original: arm9/main @ 0x0209618C; symbol: func_0209618c; size: 0x24.
extern "C" unsigned char ReadResolvedRecordThreeBitField(void* a,unsigned b) {unsigned* p=Object_FindBoundedIdEntryThrough204(a,b);if(p)return (unsigned char)((*p<<18)>>29);return 0;}
