#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_GetSpriteGroupPosition(void*,int,int*,unsigned*);
extern "C" void WfcUtility_SetSpriteGroupPosition(void*,int,unsigned,unsigned);
extern "C" void System_DispatchGlobalEntryZeroAndClearWord14(void*,void*);
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
// Original: arm9/ov031 @ 0x02236D98; symbol: Graphics_AdvancePackedXTo176AndInstallNextCallback; size: 0xa0.
// Moves packed X by8, clamps176 inside range176..256, then installs next handler.
extern "C" void Graphics_AdvancePackedXTo176AndInstallNextCallback(void* self,void*) {
 int x;unsigned y;WfcUtility_GetSpriteGroupPosition(*(void**)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]+16),0,&x,&y);x+=8;
 if(x<176||x>256){WfcUtility_SetSpriteGroupPosition(*(void**)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]+16),-1,x,33);return;}
 x=176;WfcUtility_SetSpriteGroupPosition(*(void**)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]+16),-1,x,33);WfcUtility_SetTaskCallback(self,System_DispatchGlobalEntryZeroAndClearWord14);
}
