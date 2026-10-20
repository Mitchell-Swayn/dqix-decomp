#include <globaldefs.h>
ARM
extern "C" int Network_StartSharedPairCallbacksOrSetFailureState(...);
extern "C" int WirelessConnection_RequestCompletion(...);
extern "C" int Resource_ClearTransferBufferAndDeriveInitialMode(...);
extern "C" int SetCurrentObjectFromCategory(...);
extern "C" int OnlineTransfer_SetOperationMode(...);
extern "C" int WaitForPendingContextAndClearOwner(...);
extern "C" unsigned long long _Z19GetCurrentTimestampv(...);
extern "C" int WirelessConnection_InitializeDefaultRecord(...);
extern "C" int WirelessConnection_AdvanceFallback(...);
extern "C" int WirelessConnection_PollStatus(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x02243D20; symbol: AdvanceTransferConnectionAndProgressState.
extern "C" void OnlineTransfer_AdvanceConnectionPhase(char*self){
switch(B(self,53)){case 0:WirelessConnection_InitializeDefaultRecord(self+784);SetCurrentObjectFromCategory(2);Network_StartSharedPairCallbacksOrSetFailureState();*(unsigned long long*)(self+936)=_Z19GetCurrentTimestampv()+0xefb5f7;B(self,53)=4;break;case 4:WirelessConnection_AdvanceFallback();if(WirelessConnection_RequestCompletion()){B(self,53)=5;if(W(self,900)<0x3c000)W(self,900)=0x3c000;}else if(W(self,900)<0x3c000)W(self,900)+=0x333;break;case 5:{int status=WirelessConnection_PollStatus();switch(status){case 4:B(self,53)=6;break;case 7:case 8:B(self,53)=8;break;}break;}case 6:OnlineTransfer_SetOperationMode(self,3);break;case 7:WaitForPendingContextAndClearOwner();OnlineTransfer_SetOperationMode(self,0);break;case 8:Resource_ClearTransferBufferAndDeriveInitialMode(self);WaitForPendingContextAndClearOwner();break;}
}
