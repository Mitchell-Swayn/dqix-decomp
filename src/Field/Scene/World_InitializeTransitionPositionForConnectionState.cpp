#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv(),*Network_GetConnectionManager(),*Zone3D_GetMainInstance(),*GameState_ReadUnkF8(void*),*GameState_GetFieldVisualObject(void*),*_ZN8Vector3iaSERKS_(void*,const void*);extern "C" bool Network_IsParentOrOffline(unsigned*);extern "C" void FieldTransition_InitializeRequestDefaults(char*),Network_QueueHostZonePositionAndHeading(short,short,short,unsigned char);
// Original: arm9/ov017 @ 0x02199360; symbol: World_InitializeTransitionPositionForConnectionState; size 0x120.
extern "C" void World_InitializeTransitionPositionForConnectionState(char* self){if(!B(self,0x36b8))return;void* game=_ZN9GameState11GetInstanceEv();void* connection=Network_GetConnectionManager();char* zone=(char*)Zone3D_GetMainInstance();char* record=P(self,0x36bc);char* state=(char*)GameState_ReadUnkF8(game);char* object=(char*)GameState_GetFieldVisualObject(game);if(Network_IsParentOrOffline((unsigned*)connection)){_ZN8Vector3iaSERKS_(zone+0x2774,record+0x40);W(zone,0x2780)=S(record,0x4c);FieldTransition_InitializeRequestDefaults(state);H(state,0)=10000;B(state,2)=1;B(state,7)=1;_ZN8Vector3iaSERKS_(state+16,object+0x44);H(state,28)=W(object,0x54);B(zone,0x2788)=1;Network_QueueHostZonePositionAndHeading(1,-1,1,0);}else{FieldTransition_InitializeRequestDefaults(state);H(state,0)=5900;B(state,2)=1;B(state,7)=1;W(state,16)=-0x7000;W(state,20)=737;W(state,24)=0x5e66;H(state,28)=0x3244;}}
