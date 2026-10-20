#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToSubBG0CharacterData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBB38; symbol: func_020bbb38; size: 0xC.
extern "C" void Graphics_ForwardSubBG0CharacterLoad(const void* data,unsigned offset,unsigned length){LoadToSubBG0CharacterData(data,offset,length);}
