#include <globaldefs.h>
ARM
extern "C" int Script_ExecuteFirstSatisfiedTriggerGroup(...);
extern "C" int Network_GetConnectionManager(...);
extern "C" int GameState_GetSerializedProgressState(...);
extern "C" int Network_GetLocalMemberId(...);
extern "C" int Network_UpdateMemberCountAndSessionTime(...);
extern "C" int Script_DispatchResultCommandsToWorld(...);
extern "C" int Field_ResetGroupResponseTracking(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x02199578; symbol: TrackMemberResponsesAndDispatchGroupCompletion.
extern "C" void Network_CollectFieldInteractionResponses(char*self,int unused,int index,int unused2,signed char mode){
char output0[52],output1[52];char*state=C(Network_GetConnectionManager());int selected=Network_GetLocalMemberId(state);if(index!=selected&&index!=4)return;if(!B(self+0x4000,0x448))return;Network_UpdateMemberCountAndSessionTime(state);if(++B(self,0x4444)>=B(state+0x1000,0xd)-1)B(self+0x4000,0x448)=0;if(mode==0){B(self,0x4449)=0;if(Script_ExecuteFirstSatisfiedTriggerGroup(GameState_GetSerializedProgressState(),29,output0))Script_DispatchResultCommandsToWorld(output0);Field_ResetGroupResponseTracking(self);}else{if(++B(self,0x4445)>=B(state+0x1000,0xd)-1){B(self,0x4449)=1;if(Script_ExecuteFirstSatisfiedTriggerGroup(GameState_GetSerializedProgressState(),29,output1))Script_DispatchResultCommandsToWorld(output1);Field_ResetGroupResponseTracking(self);}}
}
