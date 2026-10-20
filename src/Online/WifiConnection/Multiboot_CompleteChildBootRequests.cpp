#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern unsigned char* MultibootGetParentState_UnknownRoleZeroInitializedStorage;int Network_SetInterruptProtectedPeerStatus(unsigned,int);int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);void MB_DisconnectChild(unsigned);void Multiboot_SetParentState(unsigned short);}
// Original: arm9/ov031 @ 0x02238CA8; symbol: Network_ClearInactiveChannelMasksAndSelectState; size: 0xf8.
// Clears six channel masks atomically for inactive channels and selects completion state.
extern "C" void Multiboot_CompleteChildBootRequests(){unsigned short channel=1;unsigned short active=0;do{if(U(MultibootGetParentState_UnknownRoleZeroInitializedStorage,10)&(1<<channel)){if(Network_SetInterruptProtectedPeerStatus(channel,3))active|=1<<channel;else{unsigned short mask=~(1<<channel);int irq=_Z20DisableIRQInterruptsv();U(MultibootGetParentState_UnknownRoleZeroInitializedStorage,2)&=mask;U(MultibootGetParentState_UnknownRoleZeroInitializedStorage,4)&=mask;U(MultibootGetParentState_UnknownRoleZeroInitializedStorage,6)&=mask;U(MultibootGetParentState_UnknownRoleZeroInitializedStorage,8)&=mask;U(MultibootGetParentState_UnknownRoleZeroInitializedStorage,10)&=mask;U(MultibootGetParentState_UnknownRoleZeroInitializedStorage,12)&=mask;_Z20SetIRQInterruptStatei(irq);MB_DisconnectChild(channel);}}++channel;}while(channel<16);if(!active)Multiboot_SetParentState(7);else Multiboot_SetParentState(4);}
