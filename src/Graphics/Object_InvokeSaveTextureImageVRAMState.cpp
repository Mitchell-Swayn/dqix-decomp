#include <globaldefs.h>
#include <Graphics/VRAMAllocations.h>
// Original: arm9/main @ 0x0207DFAC; symbol: func_0207dfac; size: 0x1C.
extern "C" void Object_InvokeSaveTextureImageVRAMState(char *p){SaveTextureImageVRAMState((unsigned int *)(p+0x28));SaveTexturePaletteVRAMState((TexturePaletteVRAMState *)(p+0x60));}
