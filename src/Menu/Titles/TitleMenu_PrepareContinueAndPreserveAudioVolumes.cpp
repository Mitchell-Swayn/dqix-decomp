#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void SaveData_ReadValidateAndOptionallyRestoreBank(void*,int,int,int);extern "C" int Bgm_GetVolumeSetting(void*);extern "C" int SoundSfx_GetVolumeSetting(void*);extern "C" void Bgm_SetVolumeSetting(void*,int);extern "C" void SoundSfx_SetVolumeSetting(void*,int);extern "C" char* _ZN9GameState11GetInstanceEv();extern "C" void GameState_WriteUnknownF70(void*,int);extern "C" void GameState_SetUnk4Element0(void*,int);extern "C" void GameState_SetUnknown7f6c(void*,int);extern "C" void Menu_QueueScriptEntry(void*,unsigned);extern "C" char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant2[],Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216D504; symbol: SaveDisplayModesAndResetGameStateFlags; size: 0xac.
extern "C" int TitleMenu_PrepareContinueAndPreserveAudioVolumes(void* self){
SaveData_ReadValidateAndOptionallyRestoreBank(P(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage,16),0,0,0);B(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage,4)=Bgm_GetVolumeSetting(Main_UnknownRoleZeroInitializedStorage_Variant2);B(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage,1)=SoundSfx_GetVolumeSetting(Main_UnknownRoleZeroInitializedStorage);Bgm_SetVolumeSetting(Main_UnknownRoleZeroInitializedStorage_Variant2,3);SoundSfx_SetVolumeSetting(Main_UnknownRoleZeroInitializedStorage,3);char* state=_ZN9GameState11GetInstanceEv();GameState_WriteUnknownF70(state,0);B(state,0x7f71)=0;GameState_SetUnk4Element0(state,0);GameState_SetUnknown7f6c(state,5);Menu_QueueScriptEntry(self,999);return 0;
}
