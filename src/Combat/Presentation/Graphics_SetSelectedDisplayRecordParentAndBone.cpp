#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" void* CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" void* Combat_GetDisplayRecordSlot(void*,int);
extern "C" unsigned char* ObjectPool_GetDisplayEntryByObjectIndex(unsigned char*,int);
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(void*,const char*);
// Original: arm9/ov025 @ 0x021E509C; symbol: func_ov025_021e509c; size: 0xB0.
extern "C" int Graphics_SetSelectedDisplayRecordParentAndBone(unsigned char* command) {
 unsigned char* display=(unsigned char*)Object_GetGlobalSixteenEntryDisplayState();
 int* childEntry=(int*)Combat_GetDisplayRecordSlot(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3],command[8]);
 int* parentEntry=(int*)Combat_GetDisplayRecordSlot(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3],command[9]);
 if(!childEntry || !parentEntry) return 1;
 int parentIndex=*parentEntry;
 unsigned char* child=ObjectPool_GetDisplayEntryByObjectIndex(display,*childEntry);
 unsigned char* parent=ObjectPool_GetDisplayEntryByObjectIndex(display,parentIndex);
 if(!child || !parent) return 1;
 if(*(int*)(parent+0xac)) return 1;
 *(short*)(child+0xb2)=parentIndex;
 const char* bone=*(const char**)(command+12);
 if(bone && *(void**)(parent+8)) *(short*)(child+0xb4)=_ZN7Model3D12GetBoneIndexEPKc(*(void**)(parent+8),bone);
 return 1;
}
