#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_GetSpriteGroupPosition(void*,int,unsigned*,int*);
extern "C" void WfcKeyboard_LayoutRow(unsigned,int,int);extern "C" void WfcKeyboard_UpdateSelectionCursor();extern "C" void WfcKeyboard_UpdateInput();extern "C" void WfcUtility_SetTaskCallback(void*,void(*)());
// Original: arm9/ov031 @ 0x02224248; symbol: AdvancePackedValueToward170AndSetCallback; size: 0x8C.
// Decrements entry0 low field by12 until170 then installs the completion callback.
extern "C" void AdvancePackedValueToward170AndSetCallback(void* self){unsigned high;int low;WfcUtility_GetSpriteGroupPosition(*(void**)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0xfc),0,&high,&low);low-=12;if(low>170){WfcKeyboard_LayoutRow(*(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11d),4,low);return;}WfcKeyboard_LayoutRow(*(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11d),4,170);WfcKeyboard_UpdateSelectionCursor();WfcUtility_SetTaskCallback(self,WfcKeyboard_UpdateInput);}
