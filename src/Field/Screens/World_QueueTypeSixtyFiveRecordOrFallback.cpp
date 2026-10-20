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
extern "C" unsigned GameState_ReadProtagonistObjectIndex(...);
extern "C" unsigned LinkedQueue_IsEmpty(...);
extern "C" unsigned GameObject_HasQueuedActions(...);
extern "C" unsigned ReadAvailableMemberValueRelativeToProtagonist(...);
extern "C" unsigned TextContext_GetSharedInstance(...);
extern "C" unsigned Resource_InitializeTypeSixtyFiveRecord(...);
extern "C" unsigned Network_QueueFieldActionResponse(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState20GetUnknownGameObjectEv(...);
// Original: arm9/ov017 @ 0x021a7c94; symbol: World_QueueTypeSixtyFiveRecordOrFallback; size: 0xe4.
extern "C" void World_QueueTypeSixtyFiveRecordOrFallback(unsigned self,int index,unsigned value){
unsigned game=_ZN9GameState11GetInstanceEv(),global=TextContext_GetSharedInstance();unsigned player=_ZN9GameState20GetUnknownGameObjectEv(game);int ready=1;if(U32(global+0x998))ready=0;if(GameObject_HasQueuedActions(player))ready=0;if(!LinkedQueue_IsEmpty(U32(self+0x36fc)))ready=0;if(!ReadAvailableMemberValueRelativeToProtagonist((unsigned char)index,1,1,0))ready=0;int protagonist=GameState_ReadProtagonistObjectIndex(game);
if(ready){Resource_InitializeTypeSixtyFiveRecord(U32(self+0x3b9c));U32(U32(self+0x3b9c)+0x34)=index;U16(U32(self+0x3b9c)+0x30)=value;LinkedQueue_AppendAndMarkActive(U32(self+0x36fc),U32(self+0x3b9c));Network_QueueFieldActionResponse(4,index,protagonist,value);}else Network_QueueFieldActionResponse(5,index,protagonist,value);
}