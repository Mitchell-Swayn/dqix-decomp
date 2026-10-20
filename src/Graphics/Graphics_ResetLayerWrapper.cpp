#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Tilemap_ResetResourceDescriptor(void*);
// Original: arm9/main @ 0x0204ACD0; symbol: func_0204acd0; size: 0xC.
extern "C" void Graphics_ResetLayerWrapper(void* object){Tilemap_ResetResourceDescriptor(object);}
