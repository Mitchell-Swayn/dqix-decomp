#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void* AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage;
extern "C" int Graphics_HasIndexedSlotAnimationStopped(void*,int);
// Original: arm9/ov001 @ 0x0215A094; symbol: func_ov001_0215a094; size: 0xA0.
extern "C" int Graphics_ClearStoppedAnimationAndTestEightSlots(unsigned char* p){
 unsigned char* animation=*(unsigned char**)(p+0x18);
 if(animation && !*(int*)(animation+0x3c) && *(int*)animation==12){
 if(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage && Graphics_HasIndexedSlotAnimationStopped(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(p+0x70))){
 *(int*)(p+0x1c)=0;*(int*)(p+0x18)=0;
 }
 }
 return !*(int*)(p+8) && !*(int*)(p+0x10) && !*(int*)(p+0x18) && !*(int*)(p+0x20) && !*(int*)(p+0x28) && !*(int*)(p+0x30) && !*(int*)(p+0x38) && !*(int*)(p+0x40);
}
