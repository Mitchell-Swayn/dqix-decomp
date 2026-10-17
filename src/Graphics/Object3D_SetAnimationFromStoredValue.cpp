#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" bool _ZN8Object3D21MaybeSetBCFGAnimationEii(void*,int,int);
// Original: arm9/main @ 0x02041598; symbol: func_02041598; size: 0x18.
extern "C" bool Object3D_SetAnimationFromStoredValue(unsigned char* p,unsigned value){p[196]=value;return _ZN8Object3D21MaybeSetBCFGAnimationEii(p,value&255,*(int*)(p+208));}
