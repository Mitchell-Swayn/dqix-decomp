#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_GetLanguage(void);
// Original data: arm9/ov031 @ 0x2248958; symbol: data_ov031_02248958.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 80040000800200008002000080020000800200008002000080020000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityGetLanguageMessageLayoutParameter_UnknownRoleInitializedBytes[];

// Original: arm9/ov031 @ 0x022236D0; symbol: func_ov031_022236d0; size: 0x18.
extern "C" unsigned int WfcUtility_GetLanguageMessageLayoutParameter(void) {
    return WfcUtilityGetLanguageMessageLayoutParameter_UnknownRoleInitializedBytes[WfcUtility_GetLanguage()];
}
