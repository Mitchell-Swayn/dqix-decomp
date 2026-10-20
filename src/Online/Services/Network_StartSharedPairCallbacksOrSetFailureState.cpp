#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage[];
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void OnlineMemory_AllocateAligned();
extern "C" void OnlineMemory_FreeTagged();
extern "C" int Network_AllocateAndInitializeSharedWirelessWorkspaces(void*);
extern "C" void OnlineError_SetStatusAndDetail(int,int);
// Original: arm9/ov031 @ 0x02211CA0; symbol: Network_StartSharedPairCallbacksOrSetFailureState; size: 0xb4.
extern "C" void Network_StartSharedPairCallbacksOrSetFailureState() {
 if(*(char**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4)){if(*(unsigned short*)(*(char**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4)+4)!=1)return;
 struct Packet{void(*a)();void(*b)();unsigned char x,y;short pad;} packet;VectorizedMemset(&packet,0,12);packet.x=*(unsigned short*)(*(char**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4)+8);packet.y=*(unsigned short*)(*(char**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4)+10);packet.a=OnlineMemory_AllocateAligned;packet.b=OnlineMemory_FreeTagged;*(unsigned short*)(*(char**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4)+4)=2;if(Network_AllocateAndInitializeSharedWirelessWorkspaces(&packet))return;
 OnlineError_SetStatusAndDetail(9,-50199);return;
 }OnlineError_SetStatusAndDetail(9,-50199);
}
