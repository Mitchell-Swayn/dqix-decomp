#include <globaldefs.h>
struct Resources { char header[0x9c]; char allocator9c[0x1c]; };
extern "C" Resources* GameResources_GetInstance();
extern "C" void* func_ov017_021b2164();
extern "C" void* Object_GetGlobalThirtyTwoEntryContainer();
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" int func_ov011_021849bc(void*,unsigned);
extern "C" void func_ov011_021849ac(void*,unsigned);
extern "C" void Object_BuildPositionAndFlagSummaries(void*,unsigned);
extern "C" void Resource_ResetZoneAndAllocator();
extern "C" void GameState_ClearDisplayObjectsAndResetSlots(void*);
extern "C" void ResetThreeEmbeddedObjectsAndClearOwnerBuffer(void*);
extern "C" void GameState_DestroyFieldObjectsAndResetAllocators(void*);
extern "C" void Object_SetUnsignedIntAtOffset4(void*,unsigned);
extern "C" void func_ov017_0219b938(void*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
// Original: arm9/ov011 @ 0x02184CC0; symbol: func_ov011_02184cc0; size: 0x124.
extern "C" unsigned func_ov011_02184cc0(void* self) {
 Resources* resources=GameResources_GetInstance();
 void* owner=func_ov017_021b2164();
 void* other=Object_GetGlobalThirtyTwoEntryContainer();
 unsigned short* kind=ReadGlobalValueAt020FB3F0();
 switch(func_ov011_02184c30(self)) {
 case 0:
  if(func_ov011_021849bc(owner,1)) return 1;
  Object_BuildPositionAndFlagSummaries(other,*kind);
  Resource_ResetZoneAndAllocator();
  func_ov011_021849ac(owner,1); break;
 case 1:
  if(func_ov011_021849bc(owner,2)) return 1;
  Object_BuildPositionAndFlagSummaries(other,*kind);
  GameState_ClearDisplayObjectsAndResetSlots(resources);
  ResetThreeEmbeddedObjectsAndClearOwnerBuffer(other);
  GameState_DestroyFieldObjectsAndResetAllocators(resources);
  Object_SetUnsignedIntAtOffset4(resources,8); Object_SetUnsignedIntAtOffset4(resources,16);
  func_ov011_021849ac(owner,2); break;
 case 2:
  if(func_ov011_021849bc(owner,4)) return 1;
  func_ov017_0219b938(resources);
  _ZN13SafeAllocator5ResetEv(resources->allocator9c);
  func_ov011_021849ac(owner,4); break;
 }
 return 1;
}
