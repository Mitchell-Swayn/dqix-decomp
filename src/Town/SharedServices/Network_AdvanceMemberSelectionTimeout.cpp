#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetConnectionManager();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" int Network_GetConnectionPeerMask(void*);
extern "C" int Network_GetDiscoveredPeerCapacity(void*);
extern "C" int Network_GetDiscoveredPeerDescriptor(int,int);
extern "C" void Network_ActivateMember(unsigned char*,unsigned char);
extern "C" void Network_UpdateMemberCountAndSessionTime(unsigned char*);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
// Original: arm9/ov003 @ 0x02171640; symbol: func_ov003_02171640; size: 0xB8.
extern "C" void Network_AdvanceMemberSelectionTimeout(char* self) {
void* state=_ZN9GameState11GetInstanceEv();
unsigned char* connection=(unsigned char*)Network_GetConnectionManager();
unsigned delta=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
if(delta<*(unsigned*)(self+4)) {
*(unsigned*)(self+4)-=delta;
int mask=Network_GetConnectionPeerMask(connection);
int limit=Network_GetDiscoveredPeerCapacity(connection);
for(int i=1;i<limit;++i) {
if(mask&(1<<i)) {
Network_GetDiscoveredPeerDescriptor((int)connection,i);
self[0x199]=i;
Network_ActivateMember(connection,(unsigned char)i);
Network_UpdateMemberCountAndSessionTime(connection);
self[0]=2;
return;
}
}
} else {
*(unsigned*)(self+4)=0;
WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
self[0]=4;
}
}
