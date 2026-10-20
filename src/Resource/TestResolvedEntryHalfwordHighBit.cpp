#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int Network_IsMemberActive(void*,int);extern "C" unsigned Network_GetAssociationId();extern "C" unsigned short* Network_GetReceivedMemberPacket(void*,int);
// Original: arm9/main @ 0x0202BE08; symbol: func_0202be08; size: 0x68.
extern "C" int TestResolvedEntryHalfwordHighBit(unsigned char* p,int index){if(!Network_IsMemberActive(p,index))return 0;unsigned base=Network_GetAssociationId();unsigned short* entry;if(index==(signed char)(p+base)[0x1038])entry=(unsigned short*)(p+0x7c0);else entry=Network_GetReceivedMemberPacket(p,index);if(!entry)return 0;return (((unsigned)entry[1]<<20)>>31)!=0;}
