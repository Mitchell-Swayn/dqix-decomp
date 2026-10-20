#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
// Original: arm9/main @ 0x020406B0; symbol: func_020406b0; size: 0x48.
extern "C" void Object_HideFirstAvailableRenderTarget(unsigned char* p) { unsigned int* q=*(unsigned int**)(p+0x14);if(q) { q[20]|=1;return; }void* second=*(void**)(p+0x18);if(second) { _ZN8Object3D10MakeHiddenEv(second);return; }void* third=*(void**)(p+0x1c);if(!third)return;_ZN8Object3D10MakeHiddenEv(third); }
