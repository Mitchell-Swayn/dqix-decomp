#include <globaldefs.h>
#include <World/Object3D.h>
#pragma always_inline on
struct Words12{int values[12];};struct Bytes12{signed char values[12];};struct Bytes14{unsigned char values[14];};
extern Words12 data_020e77cc;extern Bytes12 data_020e77b0;extern Bytes14 data_020e77bc;extern const char* data_020ef978[];extern const char* data_020ef994[];extern const char data_020efa40[];
struct Nibble{unsigned char low:4,high:4;};struct Flag{unsigned char a:1,set:1,rest:6;};
// Original: arm9/main @ 0x02033BA0; symbol: func_02033ba0; size: 0x148.
extern "C" void Object_SelectRegularAnimationAndStoreIndex(Object3D* object,int animation){if(animation>=0){Words12 flags=data_020e77cc;Bytes12 replace=data_020e77b0;if(animation==0){unsigned type=((Nibble*)((char*)object+193))->high;if(type<7){Bytes14 lookup=data_020e77bc;int row=0;short id=*(short*)((char*)object+4);if(id>=192&&id<=199)row=1;if(!object->MaybeSetRegularAnimation(data_020ef978[(lookup.values+row*7)[type]],16))object->MaybeSetRegularAnimation(data_020efa40,0);if(((Flag*)((char*)object+224))->set)object->EnableFlag(0x40000);}}else {object->MaybeSetRegularAnimation(data_020ef994[animation],flags.values[animation]);if(replace.values[animation]>-1)animation=replace.values[animation];}*((unsigned char*)object+192)=animation;}}
