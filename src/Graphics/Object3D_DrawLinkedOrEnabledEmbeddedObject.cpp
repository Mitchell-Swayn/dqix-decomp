#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D4DrawEb(void*,bool);
// Original: arm9/main @ 0x0204715C; symbol: func_0204715c; size: 0x3C.
extern "C" void Object3D_DrawLinkedOrEnabledEmbeddedObject(unsigned char* p){void* q=*(void**)(p+232);if(q){_ZN8Object3D4DrawEb(q,true);return;}if(!p[29])return;_ZN8Object3D4DrawEb(p+60,true);}
