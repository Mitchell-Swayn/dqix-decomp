#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void CutsceneResource_StopOrFadeSequence(void*, void*, void*);
extern "C" void ResourceHandle_InitializeSequenceHandle(void*);
// Original data: arm9/ov001 @ 0x2165958; symbol: data_ov001_02165958.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x021638CC; symbol: func_ov001_021638cc; size: 0x70.
extern "C" int Resource_TryConfigureIndexedHandleFromScript(IntegerParameterView* parameters, int parameterIndex) {
    unsigned index = (unsigned)Script_ReadParameterAsInteger(parameters);
    if (index >= 0x10) return 0;
    unsigned* entry = &UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage[index];
    if (!*entry) return 0;
    int value = 0;
    if (parameterIndex >= 2) value = Script_ReadParameterAsInteger((IntegerParameterView*)((char*)parameters + 8));
    CutsceneResource_StopOrFadeSequence(Main_UnknownRoleZeroInitializedStorage, entry, (void*)value);
    ResourceHandle_InitializeSequenceHandle(entry);
    return 1;
}
