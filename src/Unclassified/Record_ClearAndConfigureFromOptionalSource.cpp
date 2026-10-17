#include <globaldefs.h>
extern "C" void* memset(void*,int,unsigned);
extern "C" void InitializeCoordinatesAndPackedDescriptorFlags(void*,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char);
struct Flags { unsigned char pad[1180]; unsigned char flag:1; };
struct Source { unsigned char pad[308]; unsigned value; unsigned char gap[24]; Flags* flags; };
// Original: arm9/main @ 0x020E4C74; symbol: func_020e4c74; size: 0x74.
extern "C" void Record_ClearAndConfigureFromOptionalSource(void* dest,Source* src) { memset(dest,0,12); if(src)InitializeCoordinatesAndPackedDescriptorFlags(dest,src->value,src->value,0,0,0,0,src->flags->flag,0,1,0,1); }
