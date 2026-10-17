#include <globaldefs.h>
ARM
struct LowFlags { unsigned short flags:13; unsigned short rest:3; };
extern "C" { unsigned char* ReadGlobalValueAt020FB3F0(); int _ZNK6Script9Parameter5ToIntEv(const void*); extern unsigned char* data_ov023_021fff08[]; }
struct Block { unsigned char pad[0x1b48]; unsigned first[1],second[1]; unsigned char pad2[0x11]; unsigned char pending; };
struct World { unsigned char pad[0x840]; Block block; };
// Original: arm9/ov023 @ 0x021F5AD8; symbol: func_ov023_021f5ad8; size: 0xBC.
extern "C" int GameState_MarkRequestedScriptFlags(unsigned char* parameters,int count) {
 World* world=(World*)ReadGlobalValueAt020FB3F0();
 Block* block=&world->block;
 unsigned one=1;
 for(int i=0;i<count;++i) {
  int flag=_ZNK6Script9Parameter5ToIntEv(parameters);
  parameters+=8;
  if(!(block->first[0]&(one<<flag))) {
   block->first[0]|=one<<flag;
   block->second[0]|=one<<flag;
   block->pending=one;
   LowFlags* bits=(LowFlags*)(data_ov023_021fff08[3]+0x10c);
   bits->flags=(unsigned short)(bits->flags|0x200);
  }
 }
 return 1;
}
