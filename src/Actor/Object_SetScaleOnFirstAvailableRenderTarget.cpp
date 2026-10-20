#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D8SetScaleEiii(void*,int,int,int);
// Original: arm9/main @ 0x020408C8; symbol: func_020408c8; size: 0x48.
extern "C" void Object_SetScaleOnFirstAvailableRenderTarget(void** p,int x,int y,int z){unsigned* first=(unsigned*)p[5];if(first){first[7]=x;first[8]=y;first[9]=z;return;}if(p[6]){_ZN8Object3D8SetScaleEiii(p[6],x,y,z);return;}if(p[7])_ZN8Object3D8SetScaleEiii(p[7],x,y,z);}
