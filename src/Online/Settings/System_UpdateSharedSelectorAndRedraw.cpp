#include <globaldefs.h>
ARM
// Original data: arm9/ov016 @ 0x219d0c0; symbol: data_ov016_0219d0c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
// Original data: arm9/ov031 @ 0x2248d8c; symbol: data_ov031_02248d8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0102.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2250ba4; symbol: data_ov031_02250ba4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2250bf8; symbol: data_ov031_02250bf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290c50; symbol: data_ov031_02290c50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290cf8; symbol: data_ov031_02290cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/dtcm @ 0x27e0000; symbol: data_027e0000.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8690c02c8690c02c8690c02946a0c02a46a0c02b46a0c02c46a0c02c8690c02546a0c02646a0c02746a0c02846a0c02c8690c02c8690c02c8690c02c8690c02 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/dtcm.md.
extern "C" unsigned WM_GetAllowedChannel(void); extern "C" void WfcUtility_FreeAllocationAndClearPointer(void**); extern "C" char* WfcUtility_GetEditableConnectionProfile(void); extern "C" void WfcSettingsList_RedrawVisibleRows(void); extern "C" void WfcUtility_SetAutomaticDnsAddressing(unsigned); extern "C" void WfcUtility_RemoveTaskImmediately(unsigned,...); extern "C" void WfcUtility_ReleaseOamSprite(unsigned); extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned); extern "C" void WfcUtility_DisableBottomButtonTouch(void); extern "C" void WfcUtility_SetMainLoopCallback(void(*)(void)); extern "C" void WfcUtility_BeginSetupPromptFadeOut(void); extern "C" void Graphics_ToggleMainDisplayMode(void); extern "C" void* Network_GetCommandRecordPool(void); extern "C" void Network_QueueOutgoingRecord(void*,const void*,short); extern "C" void WfcUtility_QueueBackgroundPaletteBankCopy(unsigned,unsigned,unsigned); extern "C" unsigned WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage; extern "C" unsigned StartMode6ContextCallback_UnknownRoleZeroInitializedStorage; extern "C" unsigned WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage; extern "C" unsigned WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[]; extern "C" unsigned WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage; extern "C" unsigned MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[]; extern "C" unsigned Entry_UnknownRoleProcedureReferenceRecords; extern "C" unsigned GraphicsConfigureTransformUsingSelectedByte_UnknownRoleInitializedBytes[]; extern "C" unsigned WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222f3f8; symbol: System_UpdateSharedSelectorAndRedraw; size: 0x38.
// System_UpdateSharedSelectorAndRedraw describes the observed operation.
extern "C" void System_UpdateSharedSelectorAndRedraw(unsigned selector) { char *p=WfcUtility_GetEditableConnectionProfile(); if((unsigned char)p[0xf6]==selector)return; void *g=*(void**)((char*)&StartMode6ContextCallback_UnknownRoleZeroInitializedStorage+8); *((unsigned char*)g+0x43)=selector; WfcUtility_SetAutomaticDnsAddressing(selector); WfcSettingsList_RedrawVisibleRows(); }
