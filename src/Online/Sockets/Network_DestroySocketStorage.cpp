#include <globaldefs.h>
ARM
extern "C" void Network_DrainOverlayQueueAndNotifyCancellation(...);
extern "C" void System_AppendCallbackToGlobalList(...);
extern "C" void System_RegisterPostSleepCallback(...);
extern "C" int _Z15UnblockContextsP18BlockedContextList(...);
extern "C" int _Z20DisableIRQInterruptsv(...);
extern "C" int _Z20SetIRQInterruptStatei(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkCleanupSocketStack_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x02206A68; symbol: DestroyNetworkConnectionQueuesAndUnregisterCallbacks.
extern "C" void Network_DestroySocketStorage(char*self){
if(!self)return;H(self,112)=0;int broad=1;int mode=*(signed char*)(self+115);if(mode!=0&&mode!=4)broad=0;if(broad){Network_DrainOverlayQueueAndNotifyCancellation(P(self,104));Network_DrainOverlayQueueAndNotifyCancellation(P(self,100));}else if(mode==1){char*node=P(P(self,100),260);while(node){char*next=P(node,0);((void(*)(char*))P(P(NetworkCleanupSocketStack_UnknownRoleInitializedBytes,0),28))(node);node=next;}H(P(self,100),264)=0;W(P(self,100),256)=0;P(P(self,100),260)=0;_Z15UnblockContextsP18BlockedContextList(P(self,100)+268);Network_DrainOverlayQueueAndNotifyCancellation(P(self,100));}else if(mode==2)Network_DrainOverlayQueueAndNotifyCancellation(P(self,104));int irq=_Z20DisableIRQInterruptsv();System_AppendCallbackToGlobalList(self);System_RegisterPostSleepCallback(self);((void(*)(char*))P(P(NetworkCleanupSocketStack_UnknownRoleInitializedBytes,0),28))(self);_Z20SetIRQInterruptStatei(irq);
}
