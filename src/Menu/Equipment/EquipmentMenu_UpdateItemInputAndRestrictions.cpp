#pragma force_active on
// Preserve this original entry despite fallback objects supplying only weak references.
// Original: arm9/ov005 @ 0x0215bf58; symbol: func_ov005_0215bf58; size: 0xdc.
// Updates equipment item input and records character restriction bit 0x100.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void EquipmentMenu_HandleTouchInput(void*);
extern "C" void UpdateIndexedMenuDirectionalInput(void*);
extern "C" char* GameResources_GetInstance();
extern "C" char* Field_GetSharedSubscreenInstance(void*);
extern "C" void World_SetRecordStateAndDispatchMode(void*,int,int);
extern "C" int ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" int Equipment_GetPartyRestrictionMask(int,int);
extern "C" void EquipmentMenu_UpdateItemInputAndRestrictions(char* self) {
 int done=0;
 if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] || (Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] && *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24)) || Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]){ EquipmentMenu_HandleTouchInput(self); done=1; }
 if(!done)UpdateIndexedMenuDirectionalInput(self);
 char* screen=Field_GetSharedSubscreenInstance(*(void**)(GameResources_GetInstance()+0x3708));
 int character=*(int*)(screen+0x4fc);
 int item=*(short*)(self+0x2d90+*(signed char*)(self+0x3dbb)*28);
 int state=ZoneState2754_FindPrimaryRecordByKey(*(void**)(self+0xdf4),item);
 if(state) {
 if(Equipment_GetPartyRestrictionMask((signed char)character,state)) *(unsigned short*)(self+0x19b8)|=0x100;
 else *(unsigned short*)(self+0x19b8)&=~0x100;
 }
 World_SetRecordStateAndDispatchMode(self,character,0);
}
