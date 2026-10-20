#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *);
extern "C" void SoundSfx_StopOrFadeSelectedSequence(void *, void *, int);
// Original data: arm9/ov001 @ 0x2165958; symbol: data_ov001_02165958.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x02163A18; symbol: func_ov001_02163a18; size: 0x44.
extern "C" int SoundSfx_ScriptStopIndexedSequence(IntegerParameterView *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    if (index < 0 || index >= 0x10) return 0;
    SoundSfx_StopOrFadeSelectedSequence(Main_UnknownRoleZeroInitializedStorage, UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage + index * 4, 0);
    return 1;
}
