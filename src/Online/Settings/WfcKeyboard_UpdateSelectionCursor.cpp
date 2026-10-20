#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned WfcUtility_ExpandSpriteCellTemplate(...);
extern "C" unsigned WfcUtility_GetSpriteGroupEntry(...);
extern "C" unsigned WfcUtility_SetSpriteGroupPriority(...);
extern "C" unsigned WfcUtility_SetSpriteGroupPosition(...);
// Original data: arm9/ov031 @ 0x2248ac8; symbol: data_ov031_02248ac8.
// Keyboard cursor origin table, preserved as split symbols. ConfigureSpriteFromSelectedSignedMode reads x from 0x2248ac8 + key*4 and y from 0x2248aca + key*4.
// Initial values: hex 0200.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcKeyboardUpdateSelectionCursor_KeyboardCursorOriginTablePreservedAsSplitSymbols[];
// Original data: arm9/ov031 @ 0x2248aca; symbol: data_ov031_02248aca.
// Keyboard cursor origin table, preserved as split symbols. ConfigureSpriteFromSelectedSignedMode reads x from 0x2248ac8 + key*4 and y from 0x2248aca + key*4.
// Initial values: hex 4f0014004f0026004f0038004f004a004f005c004f006e004f0080004f0092004f00a4004f00b6004f00c8004f001e0065003000650042006500540065006600 ...; full span in module reference.
// Observed span: 210 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcKeyboardUpdateSelectionCursor_KeyboardCursorOriginTablePreservedAsSplitSymbols_Variant2[];
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222506c; symbol: ConfigureSpriteFromSelectedSignedMode.
extern "C" void WfcKeyboard_UpdateSelectionCursor(){char* state=(char*)U(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage,0);unsigned index;switch(S(state,0x121)){case 47:index=66;break;case 48:index=65;break;case 49:index=67;break;case 50:index=65;break;case 51:case 52:index=69;break;default:index=64;break;}void* entry=(void*)WfcUtility_GetSpriteGroupEntry(U(state,0x114),0);WfcUtility_ExpandSpriteCellTemplate(0,index,entry);WfcUtility_SetSpriteGroupPriority(U((void*)U(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage,0),0x114),-1,2);state=(char*)U(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage,0);int mode=S(state,0x121);WfcUtility_SetSpriteGroupPosition(U(state,0x114),-1,H(WfcKeyboardUpdateSelectionCursor_KeyboardCursorOriginTablePreservedAsSplitSymbols,mode*4),H(WfcKeyboardUpdateSelectionCursor_KeyboardCursorOriginTablePreservedAsSplitSymbols_Variant2,mode*4));}
