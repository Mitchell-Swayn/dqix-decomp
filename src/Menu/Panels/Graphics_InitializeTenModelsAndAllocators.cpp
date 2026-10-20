#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN8Object3D10InitializeEv(void*);
struct Model { char bytes[0xac]; };
struct Allocator { char bytes[0x14]; };
// Original: arm9/ov023 @ 0x021E4E8C; symbol: func_ov023_021e4e8c; size: 0x8C.
extern "C" void Graphics_InitializeTenModelsAndAllocators(char* p) {
p[0xc11]=0;
for(int i=0;i<10;++i) {
_ZN8Object3D10InitializeEv(&((Model*)p)[i]);
_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x6b8+i*20);
}
_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x780);
p[0xc10]=0;
for(int i=0;i<12;++i) *(short*)(p+i*2+0xbf4)=-1;
p[0xc12]=0; p[0xc15]=0; *(int*)(p+0xc18)=0; p[0xc14]=1;
}
