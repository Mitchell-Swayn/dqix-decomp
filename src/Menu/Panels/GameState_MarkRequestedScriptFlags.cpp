#include <globaldefs.h>
ARM
struct LowFlags { unsigned short flags:13; unsigned short rest:3; };
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" { unsigned char* Zone3D_GetMainInstance(); int _ZNK6Script9Parameter5ToIntEv(const void*); extern unsigned char* ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[]; }
struct Block { unsigned char pad[0x1b48]; unsigned first[1],second[1]; unsigned char pad2[0x11]; unsigned char pending; };
struct World { unsigned char pad[0x840]; Block block; };
// Original: arm9/ov023 @ 0x021F5AD8; symbol: func_ov023_021f5ad8; size: 0xBC.
extern "C" int GameState_MarkRequestedScriptFlags(unsigned char* parameters,int count) {
 World* world=(World*)Zone3D_GetMainInstance();
 Block* block=&world->block;
 unsigned one=1;
 for(int i=0;i<count;++i) {
  int flag=_ZNK6Script9Parameter5ToIntEv(parameters);
  parameters+=8;
  if(!(block->first[0]&(one<<flag))) {
   block->first[0]|=one<<flag;
   block->second[0]|=one<<flag;
   block->pending=one;
   LowFlags* bits=(LowFlags*)(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[3]+0x10c);
   bits->flags=(unsigned short)(bits->flags|0x200);
  }
 }
 return 1;
}
