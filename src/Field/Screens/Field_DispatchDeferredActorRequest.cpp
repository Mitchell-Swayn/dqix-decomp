#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned LinkedQueue_AppendAndMarkActive(...);
extern "C" unsigned FieldBattle_ConfigureEncounterRequest(...);
extern "C" unsigned GameResources_GetInstance(...);
extern "C" unsigned FieldBattle_InitializeCommand(...);
extern "C" unsigned LinkedList_ContainsNodeByIdentity(...);
extern "C" unsigned LinkedList_ContainsTag(...);
extern "C" unsigned Zone3D_GetMainInstance(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
// Original: arm9/ov017 @ 0x021a7b38; symbol: World_QueueTypeTenDescriptorIfIdle; size: 0xe4.
extern "C" void Field_DispatchDeferredActorRequest(unsigned self){
_ZN9GameState11GetInstanceEv();unsigned resources=GameResources_GetInstance();unsigned list=U32(resources+0x36fc),record=U32(resources+0x3718);int zone=U16(Zone3D_GetMainInstance());if(U32(self+8))return;if(LinkedList_ContainsTag(list,3)){U8(self+1)=1;return;}if(U8(self+0x1a)){if((zone/100)*100!=0x170c&&zone!=0x2710){U8(self+1)=1;return;}}
if(!LinkedList_ContainsNodeByIdentity(list,record)){U32(self+0x20)=1;FieldBattle_InitializeCommand(record);FieldBattle_ConfigureEncounterRequest(record,self+12);LinkedQueue_AppendAndMarkActive(list,record);}++U32(self+8);U8(self+1)=1;
}