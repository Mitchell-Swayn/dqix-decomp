#include <globaldefs.h>
ARM
extern "C" void _ZN7Model3D21RestageTexturePaletteEv(void*);
// Original: arm9/main @ 0x02055624; symbol: func_02055624; size: 0x18.
 extern "C" void Model3D_RestagePresentTexturePalette(unsigned char* p) { void* model=*(void**)(p+0x1c); if (!model) return; _ZN7Model3D21RestageTexturePaletteEv(model); }
