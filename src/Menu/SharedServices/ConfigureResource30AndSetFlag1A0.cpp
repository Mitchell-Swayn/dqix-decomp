#include <globaldefs.h>
ARM
extern "C" void* ProfileMenu_FindControlById(void*,unsigned);
extern "C" void Menu_SetSpriteCellPaletteOverride(void*,int);
extern "C" void Menu_SetActiveSelectionGrid(void*,unsigned);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
extern "C" void ProfileMenu_PopulateSavedProfilePage(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/ov004 @ 0x2171030; symbol: data_ov004_02171030.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char* MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216986C; symbol: ConfigureResource30AndSetFlag1A0; size: 0x88.
// Configures resource key30 then sets the singleton byte1A0, notifying on its first set.
extern "C" int ConfigureResource30AndSetFlag1A0(void* self) {
void* resource=ProfileMenu_FindControlById(self,30);if(!resource)return 0;
Menu_SetSpriteCellPaletteOverride(resource,2);
Menu_SetActiveSelectionGrid(self,100);ProfileMenu_PopulateSavedProfilePage(self);Menu_QueueScriptEntry(self,70);
if(!MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage[0x1a0])SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage[0x1a0]=1;return 0;
}
