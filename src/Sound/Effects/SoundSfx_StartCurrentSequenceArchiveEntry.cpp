#include <globaldefs.h>
ARM
extern "C" int ResourceHandle_StartOrDeferSequenceArchiveEntry(char*,int,int,void*);
// Original: arm9/main @ 0x0205EAA0; symbol: func_0205eaa0; size: 0x1C.
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char* p,int a,void* b){ResourceHandle_StartOrDeferSequenceArchiveEntry(p,*(short*)(p+0xb4),a,b);}
