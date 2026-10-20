#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void ResourceHandle_StartIndexedRecordOperation(void *object, int index, void *first, void *second);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov001 @ 0x02163518; symbol: func_ov001_02163518; size: 0x28.
extern "C" int Resource_StartIndexedOperationFromScript(IntegerParameterView *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    ResourceHandle_StartIndexedRecordOperation(Main_UnknownRoleZeroInitializedStorage_Variant2, index, 0, 0);
    return 1;
}
