#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D9SetRadiusEi(void*,int);extern "C" void _ZN8Object3D9SetHeightEi(void*,int);
// Original: arm9/main @ 0x02048850; symbol: func_02048850; size: 0x2C.
extern "C" void Object3D_SetBoundsFromStoredHalfwordDescriptor(unsigned char* p,short* value){*(short**)(p+324)=value;_ZN8Object3D9SetRadiusEi(p,(int)value[6]*4);_ZN8Object3D9SetHeightEi(p,(*(short**)(p+324))[7]);}
