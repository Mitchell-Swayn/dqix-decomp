#include <globaldefs.h>
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x020698FC; symbol: func_020698fc; size: 0x28.
extern "C" ARM int WriteEncodedTextMarkerFF1F(void** object) { void* destination=*object; unsigned short marker=0xff1f; memcpy(destination,&marker,2); return 2; }
