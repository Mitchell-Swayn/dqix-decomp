#include <globaldefs.h>
ARM
#pragma opt_propagation off
#include <std_library_functions.h>
struct Tree;
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char* StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];
extern "C" void* Zone3D_GetMainInstance();
class ZoneState0840 { public: int IsValueInRangeC3b5(int); };
extern "C" Tree* Menu_FindSessionArenaById(Tree*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
// Original: arm9/ov004 @ 0x02163304; symbol: func_ov004_02163304; size: 0xA8.
extern "C" int Resource_AllocateThreeZeroedBuffersFromSelectedNode(Tree* self) {
 int id=3;
 char* state=(char*)Zone3D_GetMainInstance();
 ZoneState0840* zone=(ZoneState0840*)(state+0x840);
 if(zone) {
  int key=*(unsigned short*)state;
  if(zone->IsValueInRangeC3b5(key)) id=7;
 }
 char* node=(char*)Menu_FindSessionArenaById(self,id);
 StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[6]=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x1000);
 memset(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[6],0,0x1000);
 StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[3]=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x800);
 memset(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[3],0,0x800);
 StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[10]=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x80);
 memset(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[10],0,0x80);
 return 0;
}
