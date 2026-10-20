#include <globaldefs.h>
ARM
struct Record { char pad[0x24]; unsigned char flags; char pad2[0x27]; int index; char rest[0x3f8]; };
// Original: arm9/ov000 @ 0x0217FCC4; symbol: func_ov000_0217fcc4; size: 0x9C.
extern "C" void BattleMenu_DisablePartyCommandInput(char* self,int index) {
if(index<0) {
for(int i=0;i<4;++i) {
Record* r=(Record*)(self+0x958)+*(self+i+0x6c);
if(r->index>=0) r->flags &= ~1;
}
} else {
for(int i=0;i<4;++i) {
Record* r=(Record*)(self+0x958)+*(self+i+0x6c);
if(index==r->index) {r->flags &= ~1;return;}
}
}
}
