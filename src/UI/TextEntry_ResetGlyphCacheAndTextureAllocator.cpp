#include <globaldefs.h>
struct Item { char data[0x1c]; }; struct Owner { char pad[0x9b4]; int value; Item items[128]; unsigned char flags[128]; char pad2[0x178]; unsigned char active; char pad3[0x477]; void* child; }; extern "C" { void Object3D_InitializeExtendedAnimationWrapper(void*); void TextureVRAM_SnapshotAllocationBounds(void*);
// Original: arm9/main @ 0x02045CAC; symbol: func_02045cac; size: 0x68.
 void TextEntry_ResetGlyphCacheAndTextureAllocator(Owner* p) { p->active=1; p->value=0; for(int i=0;i<128;++i) { Object3D_InitializeExtendedAnimationWrapper(p->items+i); p->flags[i]=0; } if(p->child)TextureVRAM_SnapshotAllocationBounds(p->child); } }
