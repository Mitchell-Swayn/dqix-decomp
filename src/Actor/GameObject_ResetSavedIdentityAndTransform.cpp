#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f0420; symbol: data_020f0420.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00003443ffffffff0000f0410000f04100003443.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void __clear(void*,unsigned);extern "C" void _ZN8Vector3iaSERKS_(void*,const void*);extern "C" void* GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[2];
// Original: arm9/main @ 0x02053F04; symbol: func_02053f04; size: 0x48.
extern "C" void GameObject_ResetSavedIdentityAndTransform(unsigned char* p){unsigned xyz[3];__clear(xyz,12);*(void**)(p+348)=GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[1];_ZN8Vector3iaSERKS_(p+352,xyz);_ZN8Vector3iaSERKS_(p+364,xyz);}
