#include <globaldefs.h>
ARM
#pragma opt_propagation off
#include <std_library_functions.h>
struct Tree;
extern "C" unsigned char* data_ov004_021707e8[];
extern "C" void* ReadGlobalValueAt020FB3F0();
class ZoneState0840 { public: int IsValueInRangeC3b5(int); };
extern "C" Tree* FindTreeNodeForwarder(Tree*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
// Original: arm9/ov004 @ 0x02163304; symbol: func_ov004_02163304; size: 0xA8.
extern "C" int Resource_AllocateThreeZeroedBuffersFromSelectedNode(Tree* self) {
 int id=3;
 char* state=(char*)ReadGlobalValueAt020FB3F0();
 ZoneState0840* zone=(ZoneState0840*)(state+0x840);
 if(zone) {
  int key=*(unsigned short*)state;
  if(zone->IsValueInRangeC3b5(key)) id=7;
 }
 char* node=(char*)FindTreeNodeForwarder(self,id);
 data_ov004_021707e8[6]=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x1000);
 memset(data_ov004_021707e8[6],0,0x1000);
 data_ov004_021707e8[3]=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x800);
 memset(data_ov004_021707e8[3],0,0x800);
 data_ov004_021707e8[10]=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x80);
 memset(data_ov004_021707e8[10],0,0x80);
 return 0;
}
