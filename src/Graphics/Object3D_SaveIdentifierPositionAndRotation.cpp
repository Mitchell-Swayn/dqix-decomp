#include <globaldefs.h>
ARM
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*); extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
// Original: arm9/main @ 0x02053ED8; symbol: func_02053ed8; size: 0x2C.
 extern "C" void Object3D_SaveIdentifierPositionAndRotation(unsigned char* p) { *(unsigned int*)(p+0x15c)=_ZNK8Object3D10GetField06Ev(p); _ZN8Vector3iaSERKS_(p+0x160,p+0x44);_ZN8Vector3iaSERKS_(p+0x16c,p+0x50); }
