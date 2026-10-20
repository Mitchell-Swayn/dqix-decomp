#pragma force_active on
// Preserve this original entry despite fallback objects supplying only weak references.
// Original: arm9/ov005 @ 0x0215be60; symbol: func_ov005_0215be60; size: 0x74.
// Clears background selection, then chooses touch input or directional menu input.
extern "C" void Graphics_SelectBackgroundStateRecord(void*,int);
extern "C" void EquipmentMenu_HandleTouchInput(void*);
extern "C" void UpdateIndexedMenuDirectionalInput(void*);
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void EquipmentMenu_UpdateBrowsingInput(char* self) { Graphics_SelectBackgroundStateRecord(self+0x1244,-1); int done=0; if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] || (Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] && *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24)) || Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]) { EquipmentMenu_HandleTouchInput(self); done=1; } if(!done) UpdateIndexedMenuDirectionalInput(self); }
