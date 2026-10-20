#include <globaldefs.h>
ARM
extern "C" int Field_MarkCombatantStatusAppearanceDirty(void*,int);
extern "C" void Graphics_ModifyObjectTexturePalette(void*,int,unsigned short);
// Original: arm9/ov017 @ 0x0218F92C; symbol: func_ov017_0218f92c; size: 0x3C.
// Updates indexed combatant flags and modifies its texture palette only when allowed.
extern "C" void ModifyTexturePaletteWhenIndexedFlagsAllow(void* self,int index,unsigned short color) {
    bool allowed=Field_MarkCombatantStatusAppearanceDirty(self,index)!=0;
    if(!allowed)return;
    Graphics_ModifyObjectTexturePalette(self,index,color);
}
