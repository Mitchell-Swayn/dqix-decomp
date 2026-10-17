#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);extern "C" void _ZN8Vector3iaSERKS_(void*,const void*);extern "C" void* data_020f0420[2];
// Original: arm9/main @ 0x02053F04; symbol: func_02053f04; size: 0x48.
extern "C" void ClearTwoVectorsAndSetResourcePointer(unsigned char* p){unsigned xyz[3];__clear(xyz,12);*(void**)(p+348)=data_020f0420[1];_ZN8Vector3iaSERKS_(p+352,xyz);_ZN8Vector3iaSERKS_(p+364,xyz);}
