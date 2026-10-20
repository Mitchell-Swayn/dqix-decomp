#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" unsigned GameState_ReadByteAtOffset4(void*);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(void*,unsigned);
extern "C" void Bgm_StopPlaybackAndResetController(void*);
extern "C" void SoundSfx_RestoreSecondaryHeapStateAndVolume(char*);
extern "C" void Bgm_SetVolumeSetting(void*,int);
extern "C" void SoundSfx_SetVolumeSetting(void*,int);
extern "C" void GameResources_ClearPrimaryFlags(void*,unsigned);
extern "C" void GameResources_ClearSecondaryFlags(void*,unsigned);
extern "C" void GameResources_ClearTertiaryFlags(void*,unsigned);
extern "C" void Field_RequestSceneLoopExit(void*);
extern "C" void GameState_SetUnknown7f6c(void*,int);
extern "C" void GameState_SetUnk4Element0(void*,int);
extern "C" unsigned GameState_ReadUnknown7f70(void*);
extern "C" void GameState_WriteUnknownF70(void*,int);
extern "C" void GameState_RequestSaveErrorExit(void*);
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
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[],Main_UnknownRoleZeroInitializedStorage[],InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216D920; symbol: func_ov004_0216d920; size: 0x138.
extern "C" int GameState_ResetResourceFlagsAndApplyOverlayModes() {
 void* state=_ZN9GameState11GetInstanceEv();
 void* resources=GameResources_GetInstance();
 if(GameState_ReadByteAtOffset4(state)!=2) {
 Bgm_StopActiveSequenceUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2,0);
 Bgm_StopPlaybackAndResetController(Main_UnknownRoleZeroInitializedStorage_Variant2);
 SoundSfx_RestoreSecondaryHeapStateAndVolume((char*)Main_UnknownRoleZeroInitializedStorage);
 }
 Bgm_SetVolumeSetting(Main_UnknownRoleZeroInitializedStorage_Variant2,InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[4]);
 SoundSfx_SetVolumeSetting(Main_UnknownRoleZeroInitializedStorage,InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[1]);
 GameResources_ClearPrimaryFlags(resources,~0u);
 GameResources_ClearSecondaryFlags(resources,~0u);
 GameResources_ClearTertiaryFlags(resources,~0u);
 Field_RequestSceneLoopExit(resources);
 GameState_SetUnknown7f6c(state,5);
 if(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[2]==1 && InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[3]!=4) {
 GameState_SetUnk4Element0(state,6);
 GameState_SetUnknown7f6c(state,2);
 }
 if(GameState_ReadUnknown7f70(state)==1) {
 GameState_SetUnk4Element0(state,6);
 GameState_SetUnknown7f6c(state,0);
 GameState_WriteUnknownF70(state,0);
 }
 if(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[5]) { GameState_RequestSaveErrorExit(state); InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[5]=0; }
 return 0;
}
