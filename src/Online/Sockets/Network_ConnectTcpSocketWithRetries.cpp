#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned Network_AdvanceRandomStateAndReturnHighWord(void*);extern "C" unsigned long long _Z19GetCurrentTimestampv();extern "C" void Network_SendTcpControlOrRequestArp(void*,int,int);extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z19BlockCurrentContextP18BlockedContextList(void*);extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022032A4; symbol: RetryTimedContextOperationUntilComplete; size: 0xb4.
extern "C" int Network_ConnectTcpSocketWithRetries(char* self){
unsigned attempt;unsigned value=Network_AdvanceRandomStateAndReturnHighWord(self);attempt=0;do{W(self,40)=value;B(self,8)=2;W(self,16)=(unsigned)(_Z19GetCurrentTimestampv()>>16);Network_SendTcpControlOrRequestArp(self,2,24);int irq=_Z20DisableIRQInterruptsv();if(B(self,8)==2&&W(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,80)){W(self,4)=1;_Z19BlockCurrentContextP18BlockedContextList(0);}_Z20SetIRQInterruptStatei(irq);if(B(self,8)==4)return 0;if(!W(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,80))break;attempt++;}while(attempt<3);return 1;
}
