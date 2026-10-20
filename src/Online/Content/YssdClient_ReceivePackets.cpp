#include <globaldefs.h>
ARM
extern "C" int YssdClient_SetWorkerPhase(...);
extern "C" int _Z15UnblockContextsP18BlockedContextList(...);
extern "C" int System_SetSharedStateUnlessTwoUnderMutex(...);
extern "C" int Network_ReadAndValidateLengthPrefixedPacket(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char YssdClientRunWorker_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x02210E20; symbol: DrainStateSevenPacketsAndInvokeOptionalCallback.
extern "C" void YssdClient_ReceivePackets(void){
System_SetSharedStateUnlessTwoUnderMutex(0);_Z15UnblockContextsP18BlockedContextList(P(YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0)+0xa04);char* state=P(YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0);(void)*(volatile int*)(state+0x1b8);if(*(volatile int*)state!=7)return;char packet[1044];do{if(W(P(YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0),4)==2){YssdClient_SetWorkerPhase(5);return;}unsigned size=Network_ReadAndValidateLengthPrefixedPacket(packet);char* state=P(YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0);if(P(state,0xa0c))((void(*)(unsigned,void*))P(state,0xa0c))(size,packet);if(size<4||size!=(unsigned)W(packet,0)){YssdClient_SetWorkerPhase(5);return;}}while(W(P(YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0),0)==7);
}
