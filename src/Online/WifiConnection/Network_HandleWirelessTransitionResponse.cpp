#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/Timing.h>
ARM
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" int WM_StartDCF(void*,const void*,unsigned);
extern "C" void Network_ConsumeSharedValueAndDispatch(int,int,int,int);
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
extern "C" void StartSharedWirelessTransition();
extern "C" void Network_HandleWirelessTransitionCompletion(void* event);
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0220E258; symbol: func_ov031_0220e258; size: 0x264.
// Handles wireless response codes, updates transition tokens and submits validated payload operation17.
extern "C" void Network_HandleWirelessTransitionResponse(char* response){
switch(F(unsigned short,response,2)){
case 0:
switch((int)F(unsigned short,response,8)){
case 6:goto Done;
case 26:goto Done;
case 8:case 9:
switch(F(unsigned,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2260)){
case 10:F(unsigned short,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2282)=0;
case 8:Network_SetWirelessStateAndConnectionAlarm(12);return;
case 9:F(unsigned short,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2282)=0;F(unsigned short,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2280)=6;
case 12:StartSharedWirelessTransition();return;
case 11:goto Done;default:goto Done;
}
case 7:
if(F(unsigned,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2260)==12){Network_SetWirelessStateAndConnectionAlarm(8);StartSharedWirelessTransition();return;}
if(F(unsigned short,response,10)>=1 && F(unsigned short,response,10)<=2007){
F(unsigned short,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2282)=F(unsigned short,response,10);
switch(WM_StartDCF((void*)Network_HandleWirelessTransitionCompletion,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x1500,0x620)){
case 2:return;
case 8:Network_SetWirelessStateAndConnectionAlarm(12);Network_ConsumeSharedValueAndDispatch(1,(int)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140),0,2029);return;
case 3:default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,(int)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140),0,2038);return;
}
}
StartSharedWirelessTransition();return;
case 0:default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,(int)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140),F(unsigned short,response,8),2052);return;
}
case 1:F(unsigned short,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x22f8)=F(unsigned short,response,14);
case 6:case 11:case 12:Network_SetWirelessStateAndConnectionAlarm(8);StartSharedWirelessTransition();return;
case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,(int)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140),0,2075);return;
}
Done:return;
}
