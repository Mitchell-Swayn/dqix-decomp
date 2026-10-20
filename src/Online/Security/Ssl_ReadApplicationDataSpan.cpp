#include <globaldefs.h>
ARM
extern "C" int Network_CopyPendingBufferChunks(...);
extern "C" int Ssl_DispatchReceivedRecord(...);
extern "C" int Ssl_ReceiveAndProcessRecord(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x224c9c0; symbol: data_ov031_0224c9c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0220A594; symbol: GetPendingBufferRemainderAfterProcessingRequest.
extern "C" char* Ssl_ReadApplicationDataSpan(int* remaining,char* self){
char* context=P(self,12);if(P(context,0x824)&&!B(context,0x456)){int offset=W(context,0x82c);if(Network_CopyPendingBufferChunks(P(context,0x824)+offset,W(context,0x828)-offset,self)){((void(*)(void*))P(SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2,0))(P(context,0x824));P(context,0x824)=0;*remaining=0;return 0;}Ssl_DispatchReceivedRecord(context,P(context,0x824));if(!B(context,0x456))P(context,0x824)=0;}while(!P(context,0x824)){if(Ssl_ReceiveAndProcessRecord(self)==9){*remaining=0;return 0;}}*remaining=W(context,0x828)-W(context,0x82c);return P(context,0x824)+W(context,0x82c);
}
