#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);extern "C" void StartSharedWirelessTransition();extern "C" void Network_ConsumeSharedValueAndDispatch(int,int,int,int);extern "C" void Network_UpdateDcfSignalHistory(unsigned char);extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);extern "C" void Network_InvokeDcfReceiveCallback(void*);
// Original: arm9/ov031 @ 0x0220e584; symbol: Network_HandleWirelessTransitionCompletion; size 0x110.
extern "C" void Network_HandleWirelessTransitionCompletion(void* event){switch(H(event,2)){case 0:switch(H(event,4)){case 14:if(W(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2260)==12){Network_SetWirelessStateAndConnectionAlarm(8);StartSharedWirelessTransition();}else{Network_SetWirelessStateAndConnectionAlarm(9);Network_ConsumeSharedValueAndDispatch(0,(int)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140),0,0x872);}return;case 15:Network_UpdateDcfSignalHistory((unsigned char)(H(P(event,8),14)>>8));_Z24InvalidateDataCacheRangePKvj(P(event,8),0x620);Network_InvokeDcfReceiveCallback(P(event,8));return;default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,(int)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140),H(event,4),0x881);return;}case 4:default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,(int)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140),0,0x88c);return;}}
