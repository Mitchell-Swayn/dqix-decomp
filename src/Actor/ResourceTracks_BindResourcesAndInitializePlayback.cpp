#include <globaldefs.h>
ARM
extern "C" int Memory_AllocateAndInitialize368ByteRecord(unsigned*,unsigned);extern "C" void ResourceTracks_SetPlaybackResourceBindings(unsigned,unsigned,unsigned,unsigned);extern "C" void ResourceTracks_InitializeCurrentValuesAndSlopes(unsigned);
// Original: arm9/main @ 0x02055660; symbol: func_02055660; size: 0x6C.
extern "C" int ResourceTracks_BindResourcesAndInitializePlayback(unsigned* p,unsigned a,unsigned b,unsigned c){if(!a)return 0;if(!b)return 0;if(!c)return 0;p[0]=c;p[2]=b;p[3]=a;if(Memory_AllocateAndInitialize368ByteRecord(p+1,p[0])){ResourceTracks_SetPlaybackResourceBindings(p[1],p[3],p[2],p[0]);ResourceTracks_InitializeCurrentValuesAndSlopes(p[1]);}return 1;}
