#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(volatile short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x22496a8; symbol: data_ov031_022496a8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex e6ffffff.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int Network_IsSocketHandleInvalid(void*);extern "C" int Network_SubmitSocketEndpointSetup(void*);extern "C" int NetworkConnectSocketEndpoint_UnknownRoleInitializedBytes;
// Original: arm9/ov031 @ 0x0220572C; symbol: ConfigureConnectionRequestAndReturnStatus; size: 0xE8.
extern "C" int Network_ConnectSocketEndpoint(char* self,int value,void* request){if(Network_IsSocketHandleInvalid((void*)self)||(H(self,0x70)&8))return -28;int active=0;if(self)active=(H(self,0x70)&1)!=0;if(!active)return -39;int state=S(self,0x73);int ready=1;if(state!=0&&state!=4)ready=0;if(ready){if(H(self,0x70)&4)return S(self,0x72)==1?-30:0;if(H(self,0x70)&2)return H(self,0x70)&0x40?W(self,0x6c):NetworkConnectSocketEndpoint_UnknownRoleInitializedBytes;H(self,0x76)=value;P(self,0x78)=(char*)request;int result=Network_SubmitSocketEndpointSetup((void*)self);if(S(self,0x72)!=1)result=-26;return result;}H(self,0x76)=value;P(self,0x78)=(char*)request;return 0;}
