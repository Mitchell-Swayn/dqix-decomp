#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0222B644; symbol: InitializeOverlayProgressScreen; size: 0xD8.
extern "C" void* Memory_AllocateZeroedBlock(unsigned int, unsigned int);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*, unsigned*);
extern "C" unsigned int Network_CountRecordsWithDifferentHeader(void**);
extern "C" void Graphics_LoadProgressScreenResourcesAndPriorities(void);
extern "C" int System_ConvertSharedRegionByteToIndexPlusFive(void);
extern "C" void WfcUtility_ShowFormattedMessagePanel(unsigned,unsigned,unsigned);
extern "C" void WfcUtility_ShowFormattedMessagePanel(unsigned,unsigned,unsigned);
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(unsigned);
extern "C" void ConfigureThreeTierProgressIndicator(void);
extern "C" void Graphics_InitializePairedSpriteEntryArrays(void);
extern "C" void* Graphics_CreateBG0CanvasForScreen(int,int);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" void Graphics_UpdateFiveVisibleEntriesInTwoPasses(void);
extern "C" void WfcUtility_UpdateAccessPointSelectionHighlight(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_ConfigureDisplayBothEngines(void);
extern "C" void Graphics_WriteModuloDerivedValueToDisplayRegisters(void*,void*);
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
extern "C" void InitializeOverlayProgressScreen(void)
{
    *(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4) = (unsigned char*)Memory_AllocateZeroedBlock(0x5c, 4);
    unsigned optional;
    WfcUtility_GetScreenOperationArguments(&optional, 0);
    if (optional == 0) {
        TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[0] = 0;
        *(unsigned short*)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 2) = 0;
    }
    *(unsigned char*)(*(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4) + 0x51) = Network_CountRecordsWithDifferentHeader((void**)*(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4));
    Graphics_LoadProgressScreenResourcesAndPriorities();
    System_ConvertSharedRegionByteToIndexPlusFive();
    WfcUtility_ShowFormattedMessagePanel(0x34, (unsigned)-1, 0);
    WfcUtility_ConfigureSecondaryControlsForDisplayMode(2);
    ConfigureThreeTierProgressIndicator();
    Graphics_InitializePairedSpriteEntryArrays();
    *(void**)(*(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4) + 0xc) = Graphics_CreateBG0CanvasForScreen(0,0);
    *(void**)(*(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4) + 0x3c) = WfcUtility_CreateTaskWithBorrowedContext(1, Graphics_WriteModuloDerivedValueToDisplayRegisters, 0, 0x6e);
    Graphics_UpdateFiveVisibleEntriesInTwoPasses();
    WfcUtility_UpdateAccessPointSelectionHighlight();
    WfcUtility_SetMainLoopCallback(System_ConfigureDisplayBothEngines);

}
