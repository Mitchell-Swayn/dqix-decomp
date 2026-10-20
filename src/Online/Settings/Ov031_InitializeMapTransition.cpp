#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290cb8; symbol: data_ov031_02290cb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_LoadMainBG2CharacterPaletteAndScreen();
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive();
extern "C" void WfcUtility_ShowFormattedMessagePanel(unsigned, int, unsigned);
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(void*);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(unsigned);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void Graphics_ConfigureMode2Masks1And0x15AndStartContextTask();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02231BB0; symbol: func_ov031_02231bb0; size: 0x5C.
extern "C" ARM void Ov031_InitializeMapTransition() {
    Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage[0] = 0;
    Graphics_LoadMainBG2CharacterPaletteAndScreen();
    System_ConvertSharedRegionByteToIndexPlusFive();
    WfcUtility_ShowFormattedMessagePanel(0x37, -1, 0);
    WfcUtility_ConfigureSecondaryControlsForDisplayMode((void*)2);
    Graphics_SubmitIndexedConfiguredBuffer(0x24);
    WfcUtility_CreateAnimatedStatusSprite(0);
    WfcUtility_PlaySequenceArchiveEntry(0xb);
    WfcUtility_SetMainLoopCallback(Graphics_ConfigureMode2Masks1And0x15AndStartContextTask);
}
