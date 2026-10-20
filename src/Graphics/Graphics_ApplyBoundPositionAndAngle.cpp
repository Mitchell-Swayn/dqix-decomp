#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Vector { int x,y,z; };
extern "C" {
// Original data: arm9/main @ 0x20e7b24; symbol: data_020e7b24.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000cc00000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const Vector GraphicsApplyBoundPositionAndAngle_UnknownRoleInitializedBytes;
Vector* _ZN8Vector3iaSERKS_(void*,const Vector*);
void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);
}
// Original: arm9/main @ 0x02049E00; symbol: func_02049e00; size: 0x88.
extern "C" void Graphics_ApplyBoundPositionAndAngle(char* object) {
 if(*(char**)(object+0x13c)) {
  *(unsigned*)(*(char**)(object+0x13c)+0x20)&=~0x22;
  *(unsigned*)(*(char**)(object+0x13c)+0x20)|=1;
  Vector position=GraphicsApplyBoundPositionAndAngle_UnknownRoleInitializedBytes;
  position.x=*(int*)(*(char**)(object+0x13c)+0x10);
  position.z=*(int*)(*(char**)(object+0x13c)+0x18);
  int angle=*(int*)(*(char**)(object+0x13c)+0x14);
  _ZN8Vector3iaSERKS_(object+0x44,&position);
  Object3D_SetNormalizedAngleAndUpdatePosition(object,angle);
 }
}
