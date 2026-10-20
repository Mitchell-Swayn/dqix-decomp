#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" void* Util_FindEmptySlotInTable16(unsigned* index);
extern "C" void SoundSfx_StartCurrentGroupSequenceArchiveEntry(void* p, int a, int b);
extern "C" void Script_WriteIntegerReferenceOutput(void* output, int value);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x02163860; symbol: func_ov001_02163860; size: 0x6C.
extern "C" int Resource_DispatchScriptIndex(IntegerParameterView* parameter, int mode) {
    int value = Script_ReadParameterAsInteger(parameter);
    if (mode >= 2) {
        unsigned index;
        void* slot = Util_FindEmptySlotInTable16(&index);
        if (slot != 0)
            SoundSfx_StartCurrentGroupSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, value, (int)slot);
        Script_WriteIntegerReferenceOutput((char*)parameter + 8, index);
    } else {
        SoundSfx_StartCurrentGroupSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, value, 0);
    }
    return 1;
}
