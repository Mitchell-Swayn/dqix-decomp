#include <globaldefs.h>
ARM
extern "C" int Network_ConnectSocketEndpoint(char*,int,void*);
// Original: arm9/ov031 @ 0x02207230; symbol: Network_ConnectSocketAddress; size: 0x5C.
// Converts packet halfword+2 and word+4 from network byte order and forwards them.
extern "C" int Network_ConnectSocketAddress(char* self,char* packet){
 unsigned short h=*(unsigned short*)(packet+2);unsigned w=*(unsigned*)(packet+4);
 unsigned short swapped=((h>>8)&255)|((h<<8)&0xff00);
 unsigned word=((w>>24)&255)|((w>>8)&0xff00)|((w<<8)&0xff0000)|((w<<24)&0xff000000);
 return Network_ConnectSocketEndpoint(self,swapped,(void*)word);
}
