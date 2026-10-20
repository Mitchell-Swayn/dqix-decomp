#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);extern "C" unsigned short* Zone3D_GetMainInstance();extern "C" void* GameState_GetSerializedProgressState();extern "C" bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,void*);extern "C" void Script_DispatchResultCommandsToWorld(void*);extern "C" void Graphics_InitializeDisplayState21(char*);extern "C" void LinkedQueue_AppendAndMarkActive(void*,void*);
// Original: arm9/ov017 @ 0x02199138; symbol: QueueDisplayNodeOrProcessMatchingGroup; size: 0xac.
extern "C" void Field_DispatchFeatureTriggerOrQueueTypeTwentyOneAction(char* self){
void* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());unsigned short* global=Zone3D_GetMainInstance();if(B(P(self,0x3afc),2))return;int query[13];void* table=GameState_GetSerializedProgressState();query[3]=*global;query[9]=*(unsigned short*)P(self,0x36bc);if(Script_ExecuteFirstSatisfiedTriggerGroup(table,23,query))Script_DispatchResultCommandsToWorld(query);else{Graphics_InitializeDisplayState21(P(self,0x3afc));P(P(self,0x3afc),28)=(char*)object;*(unsigned short*)(P(self,0x3afc)+16)=*(unsigned short*)(self+0x36b6);LinkedQueue_AppendAndMarkActive(P(self,0x36fc),P(self,0x3afc));}
}
