#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D11DisableFlagEi(void*,int);
// Original: arm9/main @ 0x0203400C; symbol: func_0203400c; size: 0x20.
extern "C" void GameObject_ClearUnknownAnimationOverrideFlags(unsigned char* p){_ZN8Object3D11DisableFlagEi(p,0x40000);p[224]&=~2;}
