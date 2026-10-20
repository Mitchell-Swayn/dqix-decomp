#include <globaldefs.h>
ARM
#pragma force_active on
// Fallback contracts inferred from original pointer use and scalar status returns.
extern "C" int Network_IsSocketHandleInvalid(void*);
extern "C" int Network_SubmitSocketEndpointSetup(void*);
// Original: arm9/ov031 @ 0x022056BC; symbol: func_ov031_022056bc; size: 0x70.
// Stores a bound port on an active socket unless endpoint setup is already pending.
extern "C" unsigned Network_BindSocketPort(void* object,unsigned port)
{
 unsigned char* self=(unsigned char*)object;
 if(Network_IsSocketHandleInvalid(object))return -28;
 int valid=0;
 if(self)valid=(*(short*)(self+0x70)&1)!=0;
 if(!valid)return -39;
 if(*(short*)(self+0x70)&2)return -7;
 *(unsigned short*)(self+0x74)=port;
 if(*(signed char*)(self+0x73)!=1)return 0;
 return Network_SubmitSocketEndpointSetup(object);
}
