#include <globaldefs.h>
ARM
extern "C" void* TextCanvas_FindDisplayPartByKey(void*,int);
// Original: arm9/main @ 0x020811D0; symbol: func_020811d0; size: 0x18.
extern "C" bool TextCanvas_HasDisplayPart(void* p,int key){return TextCanvas_FindDisplayPartByKey(p,key)!=0;}
