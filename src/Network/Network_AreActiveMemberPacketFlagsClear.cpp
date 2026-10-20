#include <globaldefs.h>
struct Owner {char pad[0x1038];signed char ids[4];};struct Flags { short unused; unsigned short a:1,bits:4,rest:11; }; extern "C" { int Network_IsMemberActive(void*,int);int Network_GetAssociationId();Flags* Network_GetReceivedMemberPacket(void*,int);
// Original: arm9/main @ 0x0202BD68; symbol: func_0202bd68; size: 0xA0.
int Network_AreActiveMemberPacketFlagsClear(Owner* p,unsigned bit) { int i=0; for(;i<4;++i) { if(i>0 && *((signed char*)p+0x1038+i)==0)continue; if(!Network_IsMemberActive(p,p->ids[i]))continue; Flags* f=i==Network_GetAssociationId() ? (Flags*)((char*)p+0x7c0) : Network_GetReceivedMemberPacket(p,p->ids[i]);if(f && (f->bits&(1u<<bit)))return 0; } return 1; } }
