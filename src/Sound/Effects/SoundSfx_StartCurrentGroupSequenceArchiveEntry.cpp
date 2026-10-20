#include <globaldefs.h>
#pragma optimization_level 4
extern "C" void ResourceHandle_StartOrDeferSequenceArchiveEntry(void*,int,int,int);
// Original: arm9/main @ 0x0205EB90; symbol: func_0205eb90; size: 0x24.
extern "C" ARM void SoundSfx_StartCurrentGroupSequenceArchiveEntry(void* p,int a,int b){short index=*(short*)((char*)p+0xc4);if(index<0)return;ResourceHandle_StartOrDeferSequenceArchiveEntry(p,index,a,b);}
