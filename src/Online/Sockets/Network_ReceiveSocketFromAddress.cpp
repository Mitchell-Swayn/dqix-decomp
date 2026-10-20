#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022072D0; symbol: Network_ReadEndpointAndStoreBigEndianAddress; size: 0x90.
extern "C" int Network_ReceiveSocketData(int,int,int,unsigned short*,unsigned*,int);
extern "C" int Network_ReceiveSocketFromAddress(int a,int b,int c,int d,char* output) {
 unsigned short port;unsigned address;int result=Network_ReceiveSocketData(a,b,c,&port,&address,d);
 if(result<0)return result;if(!output)return result;
 *(unsigned short*)(output+2)=((port>>8)&255)|((port<<8)&0xff00);
 *(unsigned*)(output+4)=((address>>24)&255)|((address>>8)&0xff00)|((address<<8)&0xff0000)|((address<<24)&0xff000000);return result;
}
