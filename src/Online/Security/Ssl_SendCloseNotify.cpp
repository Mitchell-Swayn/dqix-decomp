#include <globaldefs.h>
ARM
extern "C" int Ssl_AuthenticateAndEncryptRecord(void*,void*);
extern "C" unsigned Network_SendTwoBuffersWithTimeout(void*,int,void*,int,void*);
// Original: arm9/ov031 @ 0x0220A9B0; symbol: Network_SendStateEightResetPacket; size: 0x80.
extern "C" void Ssl_SendCloseNotify(char *self) {
 char *state=*(char**)(self+12); unsigned char packet[28];
 if(*(unsigned char*)(state+0x455)==8) {
 packet[0]=21;packet[1]=3;packet[2]=0;packet[3]=0;packet[4]=2;packet[5]=1;packet[6]=0;
 int size=Ssl_AuthenticateAndEncryptRecord(state,packet);
 Network_SendTwoBuffersWithTimeout(packet,size,0,0,self);
 } *(unsigned char*)(state+0x455)=0;
}
