#include <globaldefs.h>
extern "C" void ResetStateIndicesFlagsAndTailFields(void*);extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
// Original: arm9/main @ 0x02054664; symbol: func_02054664; size: 0x3C.
extern "C" ARM void Object3D_InitializeExtendedFlagsAndByteSlots(signed char* p){ResetStateIndicesFlagsAndTailFields(p);*(unsigned short*)p|=0x1000;p[0x2d0]=-1;p[0x2d1]=-1;p[0x2d2]=0;_ZN8Object3D10EnableFlagEi(p,0x80);}
