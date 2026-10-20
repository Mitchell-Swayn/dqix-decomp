#include <globaldefs.h>
ARM
extern "C" int GameState_QueueObjectAndResourceStatus(...);
extern "C" int Zone3D_GetMainInstance(...);
extern "C" int Network_GetLocalMemberId(...);
extern "C" int Network_IsParentOrOffline(...);
extern "C" int FieldEvent_ApplyPeerSynchronizationDescriptor(...);
extern "C" int Network_QueueOtherPartyMemberPositions(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021D069C; symbol: DispatchPrimaryStateOrApplyPackedRecordUpdate.
extern "C" void Field_ApplyDirectedResourceUpdateOrReply(int index,char*record,int unused,char*resources,char*state){
Zone3D_GetMainInstance();int owner=W(resources,0x3734);if(Network_IsParentOrOffline(state)){GameState_QueueObjectAndResourceStatus(index);Network_QueueOtherPartyMemberPositions(1);}else if(index==0){struct Flags{unsigned char selected:2;unsigned char reserved:1;unsigned char kind:2;unsigned char enabled:1;unsigned char high:2;};if(Network_GetLocalMemberId(state)==((Flags*)(record+7))->selected){unsigned char message[20];unsigned char kind=((Flags*)(record+7))->kind;B(message,0)=kind;B(message,1)=B(record,4);B(message,2)=B(record,5);B(message,3)=B(record,6);H(message,4)=H(record,8);H(message,6)=H(record,10);B(message,8)=((Flags*)(record+7))->enabled;if(B(message,0)==0){H(message,10)=S(record,12);H(message,12)=H(record,14);}else if(B(message,0)==1){H(message,10)=H(record,12);H(message,12)=H(record,14);H(message,14)=H(record,16);H(message,16)=H(record,18);}FieldEvent_ApplyPeerSynchronizationDescriptor(owner,message);}}
}
