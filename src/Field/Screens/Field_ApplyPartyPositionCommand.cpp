#include <globaldefs.h>
ARM
extern "C" int GameObject_ResetFollowTrail(...);
extern "C" int Object3D_SetPositionComponents(...);
extern "C" int Vector3i_StoreComponents(...);
extern "C" int _ZN8Vector3iaSERKS_(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZN9GameState21GetPartyMemberByIndexEi(...);
extern "C" int FieldBattle_GetLifecyclePhase(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021D2B24; symbol: ApplyPartyPositionAndOptionalVectorUpdate.
extern "C" void Field_ApplyPartyPositionCommand(int unused,char*packet,int unused2,char*resources){
char*state=C(_ZN9GameState11GetInstanceEv());if(B(packet,4)==206)Vector3i_StoreComponents(state+0x7f60,W(packet,8),W(packet,12),W(packet,16));char*object=C(_ZN9GameState21GetPartyMemberByIndexEi(state,B(packet,4)));if(!object)return;char*context=P(resources+0x3000,0x734);if(B(context,3)&&B(context,0x103))return;char*gate=P(resources+0x3000,0x718);if(B(gate,2)&&!FieldBattle_GetLifecyclePhase(gate))return;GameObject_ResetFollowTrail(object);Object3D_SetPositionComponents(object,W(packet,8),W(packet,12),W(packet,16));if(B(packet,5)){int vector[3];Vector3i_StoreComponents(vector,W(packet,8),W(packet,12),W(packet,16));_ZN8Vector3iaSERKS_(object+212,vector);B(object,224)|=32;}H(object,172)=0;if(B(packet,4)==206)Object3D_SetPositionComponents(object,W(packet,8),W(packet,12),W(packet,16));
}
