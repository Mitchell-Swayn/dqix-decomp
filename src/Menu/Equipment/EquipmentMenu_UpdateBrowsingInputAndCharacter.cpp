#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void EquipmentMenu_HandleTouchInput(void*);
extern "C" void UpdateIndexedMenuDirectionalInput(void*);
extern "C" char* GameResources_GetInstance();
extern "C" char* Field_GetSharedSubscreenInstance(void*);
extern "C" void World_SetRecordStateAndDispatchMode(void*,int,int);
// Original: arm9/ov005 @ 0x0215BED4; symbol: UpdateObjectFromSharedFlagsAndResourceRecord; size: 0x84.
extern "C" void EquipmentMenu_UpdateBrowsingInputAndCharacter(void *self) {
 int updated=0;
 if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] || (Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] && *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24)) || Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]){EquipmentMenu_HandleTouchInput(self);updated=1;}
 if(!updated)UpdateIndexedMenuDirectionalInput(self);
 char *record=Field_GetSharedSubscreenInstance(*(void**)(GameResources_GetInstance()+0x3708));
 World_SetRecordStateAndDispatchMode(self,*(int*)(record+0x4fc),0);
}
