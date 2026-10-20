#include <globaldefs.h>
#include <System/Interrupts.h>
THUMB
extern "C" int Network_InitializeWirelessWorkspace(unsigned char *,unsigned);
extern "C" int Network_StartWirelessInitializationUnderIRQ(unsigned *,int);
extern "C" void Network_HandleQueueSessionWirelessEvent(const short *);
struct WirelessPartitionState { unsigned char *workspace;unsigned unknown04;unsigned *config;unsigned unknown0c,unknown10,unknown14;int state;unsigned callback;unsigned char *second;unsigned buffer; };
extern "C" WirelessPartitionState Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0221F26C; symbol: Network_InitializeQueueSessionWorkspace; size: 0xB8.
// Partitions a supplied buffer with four/32-byte alignment and advances wireless initialization under IRQ protection.
extern "C" int Network_InitializeQueueSessionWorkspace(unsigned callback,unsigned buffer,unsigned size) {
 int irq=DisableIRQInterrupts();
 unsigned config=(buffer+0x53)&~3;
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.buffer=buffer;
 unsigned aligned=config+0x2f;
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.config=(unsigned *)config;
 aligned&=~31;
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.workspace=(unsigned char *)aligned;
 aligned=(aligned+0x231f)&~31;
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.second=(unsigned char *)aligned;
 aligned=(aligned+0xdf)&~31;
 ((unsigned *)config)[1]=aligned;
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.config[2]=buffer+size-Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.config[1];
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.config[3]=0;
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.config[0]=3;
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.callback=callback;
 if(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.state==0) {
 if(Network_InitializeWirelessWorkspace(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.workspace,0x2300)) {SetIRQInterruptState(irq);return 0;}
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.state=1;
 }
 if(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.state==1) {
 if(Network_StartWirelessInitializationUnderIRQ(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.config,(int)Network_HandleQueueSessionWirelessEvent)!=3) {SetIRQInterruptState(irq);return 0;}
 Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage.state=4;
 SetIRQInterruptState(irq);return 1;
 }
 SetIRQInterruptState(irq);return 0;
}
