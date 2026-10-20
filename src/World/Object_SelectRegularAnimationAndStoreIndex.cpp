#include <globaldefs.h>
#include <World/Object3D.h>
#pragma always_inline on
struct Words12{int values[12];};struct Bytes12{signed char values[12];};struct Bytes14{unsigned char values[14];};
// Original data: arm9/main @ 0x20e77b0; symbol: data_020e77b0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff0000ffffffffffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e77bc; symbol: data_020e77bc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00010203040506000100000000060000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e77cc; symbol: data_020e77cc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 10000000100000000000000000000000100000001000000000000000010000000100000001000000010000000100000005050000.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ef978; symbol: data_020ef978.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 29f90e023bf90e024df90e0224f90e022ff90e0247f90e0261f90e02.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ef994; symbol: data_020ef994.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 29f90e0220f90e0220f90e0220f90e0229f90e0229f90e026ff90e0268f90e0241f90e0253f90e025af90e0235f90e02.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Words12 ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleInitializedBytes_Variant3;extern Bytes12 ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleInitializedBytes;extern Bytes14 ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleInitializedBytes_Variant2;extern const char* ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleDataReferences[];extern const char* ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleDataReferences_Variant2[];extern const char Object_SelectRegularAnimationAndStoreIndex_TextStand[];
struct Nibble{unsigned char low:4,high:4;};struct Flag{unsigned char a:1,set:1,rest:6;};
// Original: arm9/main @ 0x02033BA0; symbol: func_02033ba0; size: 0x148.
extern "C" void Object_SelectRegularAnimationAndStoreIndex(Object3D* object,int animation){if(animation>=0){Words12 flags=ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleInitializedBytes_Variant3;Bytes12 replace=ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleInitializedBytes;if(animation==0){unsigned type=((Nibble*)((char*)object+193))->high;if(type<7){Bytes14 lookup=ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleInitializedBytes_Variant2;int row=0;short id=*(short*)((char*)object+4);if(id>=192&&id<=199)row=1;if(!object->SetAnimationByName(ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleDataReferences[(lookup.values+row*7)[type]],16))object->SetAnimationByName(Object_SelectRegularAnimationAndStoreIndex_TextStand,0);if(((Flag*)((char*)object+224))->set)object->EnableFlag(0x40000);}}else {object->SetAnimationByName(ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleDataReferences_Variant2[animation],flags.values[animation]);if(replace.values[animation]>-1)animation=replace.values[animation];}*((unsigned char*)object+192)=animation;}}
