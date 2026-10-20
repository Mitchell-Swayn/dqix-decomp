#include <globaldefs.h>
ARM
extern "C" int GameState_GetObjectWithFlag100(...);
extern "C" int Network_QueueOutgoingRecord(...);
extern "C" int Object_SetHalfword1B2WhenMemberListedOrForced(...);
extern "C" int Network_GetCommandRecordPool(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int PartyStatus_ResetSelectedRemoteMemberAnimations(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021C60A4; symbol: EmitType101PacketAndUpdateFlaggedPartyMembers; size: 0xc8.
extern "C" void Network_QueueEncounterPartySelection(char* source){
void* queue=(void*)Network_GetCommandRecordPool();char packet[20];B(packet,0)=101;H(packet,4)=H(source,0);H(packet,6)=H(source,2);struct FourBytes{unsigned char bytes[4];};*(FourBytes*)(packet+8)=*(FourBytes*)(source+4);B(packet,12)=B(source,8);B(packet,13)=B(source,9);H(packet,14)=S(source,10);Network_QueueOutgoingRecord(queue,packet,0);void* state=(void*)_ZN9GameState11GetInstanceEv();for(unsigned i=0;i<4;i++){if(*(signed char*)(source+4+i)){void* object=(void*)GameState_GetObjectWithFlag100(state,i);if(object)Object_SetHalfword1B2WhenMemberListedOrForced(object,H(source,0),1);}}PartyStatus_ResetSelectedRemoteMemberAnimations(packet+8);
}
