#include <globaldefs.h>
ARM
#pragma optimization_level 2
extern "C" { void* GameResources_GetInstance(); void Graphics_RestoreTextureImageAndPaletteVRAMState(void*); void Object_InvokeSaveTextureImageVRAMState(char*); unsigned AllocateTexturePaletteVRAM(unsigned,unsigned,unsigned); }
struct SavedState { union { struct { unsigned image,palette; }; unsigned long long combined; }; };
// Original: arm9/ov000 @ 0x0216733C; symbol: func_ov000_0216733c; size: 0xA4.
extern "C" void Graphics_AllocateTexturePaletteSlots(unsigned char* p) {
 GameResources_GetInstance();
 *(SavedState*)(p+0x21c)=*(SavedState*)(p+0x214);
 Graphics_RestoreTextureImageAndPaletteVRAMState(p+0x1bc);
 int count=*(unsigned char*)(*(unsigned char**)(p+0x29c)+0x81b0);
 unsigned size;
 if(count>5) { p[0x5e00]=8; size=256; }
 else { p[0x5e00]=5; size=400; }
 for(int i=0;i<p[0x5e00];++i) *(unsigned*)(p+i*4+0x5e04)=AllocateTexturePaletteVRAM(size,0,0);
 Object_InvokeSaveTextureImageVRAMState((char*)p+0x1bc);
 p[0x5e01]=0;
}
