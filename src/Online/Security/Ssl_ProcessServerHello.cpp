#include <globaldefs.h>
ARM
#pragma opt_propagation off
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern "C" void SslSessionCache_InvalidateSession(void*);
// Original: arm9/ov031 @ 0x02208940; symbol: Network_ApplyPeerIdentifierAndBigEndianPort; size: 0xb4.
extern "C" void Ssl_ProcessServerHello(char* self,unsigned char* packet) {
 MI_CpuCopy8(packet+2,self+84,32);unsigned prior=*(unsigned char*)(self+48);unsigned size=packet[34];packet+=35;
 if(prior && size==32 && !RuntimeMemory_CompareByteRanges(self+116,packet,32))*(unsigned char*)(self+49)=1;
 else{if(prior)SslSessionCache_InvalidateSession(self);if(size){MI_CpuCopy8(packet,self+116,32);*(unsigned char*)(self+48)=1;}else *(unsigned char*)(self+48)=0;*(unsigned char*)(self+49)=0;}
 *(unsigned short*)(self+50)=(packet[size]<<8)+*(packet+size+1);*(unsigned char*)(self+0x455)=2;
}
