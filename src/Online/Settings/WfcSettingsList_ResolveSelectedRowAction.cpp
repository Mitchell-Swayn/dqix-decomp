#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x224903c; symbol: data_ov031_0224903c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00010e0405060e090a000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[],WfcSettingsListHitTestAction_UnknownRoleInitializedBytes_Variant3[];
extern "C" int FastIntDivide(int,int);
extern "C" char* WfcUtility_GetEditableConnectionProfile();
extern "C" void WfcSettingsList_UpdateSelectionHighlight();
// Original: arm9/ov031 @ 0x022308D4; symbol: ResolveSelectionStateFromSharedFlags; size: 0xb0.
// Resolves shared selection byte using row division29 and flagsF5/F6, then refreshes state.
extern "C" void WfcSettingsList_ResolveSelectedRowAction(){
 if((unsigned char)(B(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,0)+245)<=2){WfcSettingsList_UpdateSelectionHighlight();return;}
 char* shared=WfcUtility_GetEditableConnectionProfile();int index=B(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,2)+FastIntDivide((unsigned short)H(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,4),29);
 switch(index){case 2:if(B(shared,0xf5))B(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,0)=2;else B(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,0)=3;break;
 case 6:if(B(shared,0xf6))B(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,0)=7;else B(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,0)=8;break;
 default:B(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,0)=WfcSettingsListHitTestAction_UnknownRoleInitializedBytes_Variant3[index];break;}WfcSettingsList_UpdateSelectionHighlight();
}
