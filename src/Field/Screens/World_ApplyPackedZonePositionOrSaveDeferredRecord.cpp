#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" int Network_GetLocalMemberId(char*);extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);extern "C" void FieldVisualActor_RestoreZoneVisibilityAndPlacement(void*,int);
// Original: arm9/ov017 @ 0x021d1b10; symbol: World_ApplyPackedZonePositionOrSaveDeferredRecord; size 0x11c.
extern "C" void World_ApplyPackedZonePositionOrSaveDeferredRecord(int unused,void* record,int ignored,void* resources,char* indexed){if(!Network_GetLocalMemberId(indexed))return;char* zone=(char*)Zone3D_GetMainInstance();char* pending=P(resources,0x370c);char* gate=P(resources,0x3734);if(B(pending,3)&&B(pending,1)!=1){S(pending,0x12)=S(record,4);S(pending,0x14)=S(record,6);H(pending,0x16)=H(record,8);H(pending,0x18)=H(record,10);H(pending,0x1a)=H(record,12);S(pending,0x1c)=S(record,14);B(pending,0x1e)=B(record,16);}else{H(zone,0x2786)=S(record,4);int value=(S(record,6)<<18)>>18;if(value!=-1)H(zone,0x2784)=value;B(zone,0x2788)=(S(record,6)<<16)>>30;int pos[3];pos[0]=S(record,8)<<7;pos[1]=S(record,10)<<7;pos[2]=S(record,12)<<7;_ZN8Vector3iaSERKS_(zone+0x2774,pos);W(zone,0x2780)=S(record,14);if(!B(gate,3))FieldVisualActor_RestoreZoneVisibilityAndPlacement(zone,B(record,16));}}
