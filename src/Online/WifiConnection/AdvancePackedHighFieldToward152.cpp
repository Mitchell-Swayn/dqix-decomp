#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];extern "C" void WfcUtility_GetSpriteGroupPosition(void*,int,int*,unsigned*);extern "C" void WfcUtility_SetSpriteGroupPosition(void*,int,int,int);extern "C" void WfcUtility_SetTaskCallback(void*,void(*)());extern "C" void WfcUtility_SlideTrailingSpritePairLeft();
// Original: arm9/ov031 @ 0x02236F88; symbol: AdvancePackedHighFieldToward152; size: 0x94.
// Decreases the high packed field by8, clamps to152, and installs a completion callback.
extern "C" void AdvancePackedHighFieldToward152(void* self){int high;unsigned low;WfcUtility_GetSpriteGroupPosition(*(void**)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]+0x10),0,&high,&low);high-=8;if(high>152){WfcUtility_SetSpriteGroupPosition(*(void**)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]+0x10),-1,high,33);return;}high=152;WfcUtility_SetSpriteGroupPosition(*(void**)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]+0x10),-1,high,33);WfcUtility_SetTaskCallback(self,WfcUtility_SlideTrailingSpritePairLeft);}
