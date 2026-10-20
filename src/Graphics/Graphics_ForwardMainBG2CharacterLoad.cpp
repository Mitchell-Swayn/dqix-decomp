#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBA50; symbol: func_020bba50; size: 0xC.
extern "C" void Graphics_ForwardMainBG2CharacterLoad(const void* data,unsigned offset,unsigned length){LoadToMainBG2CharacterData(data,offset,length);}
