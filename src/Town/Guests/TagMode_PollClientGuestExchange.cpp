#include <globaldefs.h>
ARM
extern "C" int Network_RemoveMember(...);
extern "C" int Network_GetDiscoveredPeerDescriptor(...);
extern "C" int Network_GetConnectionManager(...);
extern "C" int Network_TestMemberDisconnectFlag(...);
extern "C" int Network_GetCommandRecordPool(...);
extern "C" int Network_IsOutgoingRecordQueueDrained(...);
extern "C" int Util_TouchSixByteKeyInFiftyEntryCache(...);
extern "C" int WaitForStateThreeThenProcessOwnerWithTimeout(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZNK9GameState21GetEffectiveDeltaTimeEv(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x02171BA0; symbol: PollIndexedConnectionUntilQueueCompletesOrTimeout.
extern "C" void TagMode_PollClientGuestExchange(char*self){
int state=_ZN9GameState11GetInstanceEv();int connection=Network_GetConnectionManager();int queue=Network_GetCommandRecordPool();if(Network_TestMemberDisconnectFlag(connection,B(self,409)))Network_RemoveMember(connection,B(self,409));W(self,0x72c)+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);if((unsigned)W(self,0x72c)>3000){WaitForStateThreeThenProcessOwnerWithTimeout(connection);B(self,0)=0;return;}if(Network_TestMemberDisconnectFlag(connection,0)&&!W(self,0x71c)){Network_GetDiscoveredPeerDescriptor(connection,B(self,409));WaitForStateThreeThenProcessOwnerWithTimeout(connection);B(self,0)=0;return;}if(W(self,0x720)&&W(self,0x71c)){char*entry=C(Network_GetDiscoveredPeerDescriptor(connection,B(self,409)));Util_TouchSixByteKeyInFiftyEntryCache(self,entry+104);WaitForStateThreeThenProcessOwnerWithTimeout(connection);B(self,0)=0;}if(Network_IsOutgoingRecordQueueDrained(queue))W(self,0x720)=1;
}
