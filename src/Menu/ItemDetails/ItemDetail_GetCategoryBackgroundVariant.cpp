#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21fd563; symbol: data_ov023_021fd563.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0201.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char ItemDetailGetCategoryBackgroundVariant_UnknownRoleInitializedBytes[];
// Original: arm9/ov023 @ 0x021DCB70; symbol: func_ov023_021dcb70; size: 0x34.
extern "C" int ItemDetail_GetCategoryBackgroundVariant(volatile unsigned int *value) {
    if (value == 0)
        return 0;
    unsigned int type = (value[2] << 28) >> 28;
    unsigned int index = type <= 7;
    return ItemDetailGetCategoryBackgroundVariant_UnknownRoleInitializedBytes[index];
}
