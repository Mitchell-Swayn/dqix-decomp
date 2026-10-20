#include <globaldefs.h>
#pragma optimization_level 4
extern "C" void LoadToMainObjStandardPalette(void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBAB0; symbol: func_020bbab0; size: 0xC.
extern "C" ARM void Graphics_ForwardMainObjectStandardPaletteLoad(void* p,unsigned a,unsigned b){LoadToMainObjStandardPalette(p,a,b);}
