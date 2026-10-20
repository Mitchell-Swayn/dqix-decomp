#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void *Util_FindEmptySlotInTable16(unsigned int *);
extern "C" void SoundSfx_StartSecondarySequenceArchiveEntry(void *, int, int);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x021639AC; symbol: Grotto_ApplyScriptValueToIndexedRecord; size: 0x6C.
extern "C" int Grotto_ApplyScriptValueToIndexedRecord(void *parameter, int parameterCount) {
    int value = Script_ReadParameterAsInteger(parameter);
    int index;
    if (parameterCount >= 2) {
        void *record = Util_FindEmptySlotInTable16((unsigned int *)&index);
        if (record != 0)
            SoundSfx_StartSecondarySequenceArchiveEntry(&Main_UnknownRoleZeroInitializedStorage, value, (int)record);
        Script_WriteIntegerReferenceOutput((char *)parameter + 8, index);
    } else {
        SoundSfx_StartSecondarySequenceArchiveEntry(&Main_UnknownRoleZeroInitializedStorage, value, 0);
    }
    return 1;
}
