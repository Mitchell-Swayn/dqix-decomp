#include <globaldefs.h>
ARM
extern "C" int Network_ValidateUnicastEndpointAddressPair(...);
extern "C" int _Z28CycleCurrentPriorityContextsv(...);
extern "C" int Network_FindListeningTcpSocket(...);
extern "C" int Network_InitializePassiveTcpHandshake(...);
extern "C" int Network_HandleSynForExistingTcpSocket(void*,void*,int);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0220225C; symbol: ValidateByteSwappedEndpointPairAndRetryContextLookup.
extern "C" void Network_HandleTcpSynchronizeSegment(char* self,void* key,int mode){
unsigned short d=H(self,18),c=H(self,16),b=H(self,14),a=H(self,12);unsigned short sa=(a>>8)|(a<<8),sb=(b>>8)|(b<<8),sc=(c>>8)|(c<<8),sd=(d>>8)|(d<<8);if(!Network_ValidateUnicastEndpointAddressPair(((unsigned)sa<<16)|sb,((unsigned)sc<<16)|sd))return;if(Network_HandleSynForExistingTcpSocket(self,key,mode))return;void* context=(void*)Network_FindListeningTcpSocket(self,key);if(context){Network_InitializePassiveTcpHandshake(self,key,context);return;}_Z28CycleCurrentPriorityContextsv();context=(void*)Network_FindListeningTcpSocket(self,key);if(context)Network_InitializePassiveTcpHandshake(self,key,context);
}
