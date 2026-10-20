#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <std_library_functions.h>
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define C(p,o) (*(signed char*)((char*)(p)+(o)))
#define V(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x22493a0; symbol: data_ov031_022493a0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00f0001011100100f0001000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290d34; symbol: data_ov031_02290d34.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[];extern "C" void* WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage;extern "C" int FastIntDivide(int,int);extern "C" void ColorEffect_ChangeBrightness(int,int);extern "C" void WfcUtility_RequestTaskRemoval(unsigned,unsigned);
// Original: arm9/ov031 @ 0x0223c150; symbol: Graphics_AdvancePairedScreenBrightnessRamp.
extern "C" void WfcUtility_AdvanceScreenBrightnessTransition(unsigned owner,char* state){
unsigned char modes[4]={WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[4],WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[5],WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[6],WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[7]};signed char endpoints[4]={(signed char)WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[0],(signed char)WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[1],(signed char)WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[2],(signed char)WfcUtilityStartScreenBrightnessTransition_UnknownRoleInitializedBytes[3]};++S(state,4);int value=FastIntDivide(S(state,4)<<4,H(state,6));unsigned mode=modes[B(state,8)];if(mode&1)value=16-value;if(mode&16)value=-value;if(state==WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage)ColorEffect_ChangeBrightness(0x4001050,value);else ColorEffect_ChangeBrightness(0x4000050,value);if(S(state,4)<H(state,6))return;if(state==WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage)ColorEffect_ChangeBrightness(0x4001050,endpoints[B(state,8)]);else ColorEffect_ChangeBrightness(0x4000050,endpoints[B(state,8)]);B(state,9)=0;WfcUtility_RequestTaskRemoval(1,owner);
}
