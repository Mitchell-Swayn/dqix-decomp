#include <globaldefs.h>
extern "C" int Field_MarkCombatantStatusAppearanceDirty(void*, unsigned, unsigned);
extern "C" int Graphics_ApplyMemberModelPaletteColor(void*, unsigned, unsigned);
// Original: arm9/ov017 @ 0x0218FCF8; symbol: func_ov017_0218fcf8; size: 0x3C.
extern "C" int Resource_ApplyUpdateOnlyWhenValidationPasses(void* object, unsigned first, unsigned second) {
    int success = Field_MarkCombatantStatusAppearanceDirty(object, first, second) != 0;
    if (success == 0) return success;
    return Graphics_ApplyMemberModelPaletteColor(object, first, second);
}
