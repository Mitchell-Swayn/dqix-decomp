#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned short StatusMenu_TestUnlockedVocation(const unsigned char*,unsigned);
// Original data: arm9/ov004 @ 0x2170854; symbol: data_ov004_02170854.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov004 @ 0x2170838; symbol: data_ov004_02170838.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 13 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0215E9DC; symbol: func_ov004_0215e9dc; size: 0x144.
extern "C" unsigned char StatusMenu_CycleAvailableVocation(void*,int objectIndex,unsigned char index,int forward) {
 unsigned char* obj=(unsigned char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),objectIndex);
 if(StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant3[index]) {
  if(forward) {
   index=(unsigned char)(index+1)%13;
   if(!index) index=1;
  } else {
   index--;
   if(index<1) index=12;
  }
  while(!StatusMenu_TestUnlockedVocation(obj,StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant3[index]) || !StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage[index]) {
   if(forward) {
    index=(unsigned char)(index+1)%13;
    if(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[2] && !index) ++index;
    if(StatusMenu_TestUnlockedVocation(obj,StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant3[index]) && StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage[index]) break;
   } else {
    --index;
    if(index<1) index=12;
    if(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[2] && !index) index=12;
    if(StatusMenu_TestUnlockedVocation(obj,StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant3[index]) && StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage[index]) break;
   }
  }
 }
 return index;
}
