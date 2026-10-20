#include <globaldefs.h>
ARM
extern "C" int Network_ParseTcpMaximumSegmentSize(...);
extern "C" unsigned long long _Z19GetCurrentTimestampv(...);
extern "C" int Network_ParseTcpMaximumSegmentSize(...);
extern "C" int Network_SendTcpControlOrRequestArp(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x022020E8; symbol: InitializeTcpConnectionFromNetworkHeaders.
extern "C" void Network_InitializePassiveTcpHandshake(char*packet,char*other,char*connection){
B(connection,8)=3;W(connection,16)=(unsigned)(_Z19GetCurrentTimestampv()>>16);{unsigned short a=H(packet,18),b=H(packet,16);unsigned short sa=(a>>8)|(a<<8),sb=(b>>8)|(b<<8);W(connection,20)=((unsigned)sb<<16)|sa;}{unsigned short port=H(other,0);H(connection,24)=(port>>8)|(port<<8);}{unsigned short a=H(packet,14),b=H(packet,12);unsigned short sa=(a>>8)|(a<<8),sb=(b>>8)|(b<<8);W(connection,28)=((unsigned)sb<<16)|sa;}{unsigned short a=H(other,6),b=H(other,4);unsigned short sa=(a>>8)|(a<<8),sb=(b>>8)|(b<<8);W(connection,36)=(((unsigned)sb<<16)|sa)+1;}Network_ParseTcpMaximumSegmentSize(other,connection);Network_SendTcpControlOrRequestArp(connection,18,0);
}
