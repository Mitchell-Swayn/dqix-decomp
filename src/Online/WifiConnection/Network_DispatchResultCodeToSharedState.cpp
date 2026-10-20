#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
extern "C" void StartSharedWirelessTransition();
extern "C" void Network_ConsumeSharedValueAndDispatch(int,void*,int,int);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0220E4BC; symbol: Network_DispatchResultCodeToSharedState; size: 0xc8.
// Dispatches result halfword into shared network state and callback arguments.
extern "C" void Network_DispatchResultCodeToSharedState(char* result){switch(H(result,2)){case 0:if(W(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2260)==12){Network_SetWirelessStateAndConnectionAlarm(10);StartSharedWirelessTransition();}else{H(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2282)=0;Network_SetWirelessStateAndConnectionAlarm(3);Network_ConsumeSharedValueAndDispatch(0,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140,0,0x83d);}break;case 1:case 3:Network_SetWirelessStateAndConnectionAlarm(10);StartSharedWirelessTransition();break;case 2:case 4:default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140,0,0x84f);break;}}
