#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f28dc; symbol: data_020f28dc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex cc580c0224590c02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f28f4; symbol: data_020f28f4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 3caf0d0220af0d02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f28fc; symbol: data_020f28fc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6caf0d0254af0d02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void(*DisplayOverlayDeactivateAndRestoreDisplay_UnknownRoleProcedureReferenceRecords[])(unsigned);extern unsigned(*DisplayOverlayCaptureNormalPlaneMasks_UnknownRoleProcedureReferenceRecords[])();extern void(*GraphicsFlushAndUploadActiveBankData_UnknownRoleProcedureReferenceRecords[])(unsigned);extern "C" void System_PushInterruptFourEnabledStateAndDisable();extern "C" void Interrupts_UpdateTimerOneFromShiftingGlobalMask();extern "C" void DisplayOverlay_CaptureNormalPlaneMasks(void*);extern "C" void Graphics_SetSelectedScreenBrightnessAndMarkEnabled(void*,unsigned,int,int);extern "C" void DMAFillAndInvokeIndexedGraphicsLoader(void*,unsigned);extern "C" void* SystemState_GetGlobalFlags();extern "C" void SystemState_ClearFlags(void*,unsigned);extern "C" void DisplayOverlay_ResetActivationState(void*);extern "C" void Graphics_EnableUpdateAndApplyBrightnessTransitions(void*);
// Original: arm9/main @ 0x020DB894; symbol: func_020db894; size: 0xD0.
extern "C" void DisplayOverlay_DeactivateAndRestoreDisplay(unsigned char* object){if(!object[0x51])return;System_PushInterruptFourEnabledStateAndDisable();DisplayOverlay_CaptureNormalPlaneMasks(object);if(object[0x53]){Graphics_SetSelectedScreenBrightnessAndMarkEnabled(object,object[0x3c],*(short*)(object+0x6a),0);DisplayOverlayDeactivateAndRestoreDisplay_UnknownRoleProcedureReferenceRecords[6](*(unsigned*)(object+0x5c));DisplayOverlayDeactivateAndRestoreDisplay_UnknownRoleProcedureReferenceRecords[7](*(unsigned*)(object+0x60));}else if(!object[0x64]){unsigned value=DisplayOverlayCaptureNormalPlaneMasks_UnknownRoleProcedureReferenceRecords[object[0x3c]]();GraphicsFlushAndUploadActiveBankData_UnknownRoleProcedureReferenceRecords[object[0x3c]](value&~0x10);}DMAFillAndInvokeIndexedGraphicsLoader(object,object[0x3c]);void* flags=SystemState_GetGlobalFlags();SystemState_ClearFlags(flags,0x8000);DisplayOverlay_ResetActivationState(object);Graphics_EnableUpdateAndApplyBrightnessTransitions(object);Interrupts_UpdateTimerOneFromShiftingGlobalMask();}
