#include <globaldefs.h>
// Original: arm9/ov023 @ 0x021e6158; symbol: func_ov023_021e6158; size: 0x14.
extern "C" void CharacterPreview_InvalidateComponentId(char* p,unsigned int i) { short marker=-1; *(short*)(p+i*0xAC+2)=marker; }
