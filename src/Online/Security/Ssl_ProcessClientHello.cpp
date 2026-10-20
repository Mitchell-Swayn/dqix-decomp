#include <globaldefs.h>
ARM
extern "C" int Ssl_IsProtocolMajorVersionSupported(int,int);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void SslSessionCache_RestoreMasterSecret(unsigned char*);
extern "C" int Buffer_FindFirstSharedHalfwordByStride(void*,int,int);
// Original: arm9/ov031 @ 0x02208B78; symbol: CopyValidatedPacketRecordsAndHalfwords; size: 0x9c.
// Copies validated packet fields and optional32-byte record; decodes big endian byte count and stores parsed halfword result.
extern "C" void Ssl_ProcessClientHello(unsigned char* p,unsigned char* packet){
 if(!Ssl_IsProtocolMajorVersionSupported(packet[0],packet[1]))return;
 MI_CpuCopy8(packet+2,p+0x34,32);unsigned length=packet[0x22];unsigned char* start=packet+0x23;
 if(length!=32)p[0x30]=0;else{MI_CpuCopy8(start,p+0x74,32);SslSessionCache_RestoreMasterSecret(p);}
 unsigned char* tail=start+length;int low=tail[1];int high=start[length];int count=(high<<8)+low;
 unsigned short result=Buffer_FindFirstSharedHalfwordByStride(tail+2,count/2,2);*(unsigned short*)(p+0x32)=result;if(result)p[0x455]=1;
}
