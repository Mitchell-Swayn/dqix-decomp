#include <globaldefs.h>
ARM

extern "C" unsigned int WfcUtility_GetLanguage(void);
// Original data: arm9/ov031 @ 0x2250bb0; symbol: data_ov031_02250bb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityLocalizeResourcePath_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char WfcUtility_LocalizeResourcePath_TextJefgisk[];
extern "C" char *strncpy(char *, const char *, unsigned int);

// Original: arm9/ov031 @ 0x02223478; symbol: func_ov031_02223478; size: 0x60.
extern "C" char *WfcUtility_LocalizeResourcePath(const char *source) {
    strncpy(WfcUtilityLocalizeResourcePath_UnknownRoleZeroInitializedStorage, source, 0x3f);
    if ((unsigned char)source[5] == 0x78) {
        return WfcUtilityLocalizeResourcePath_UnknownRoleZeroInitializedStorage;
    }
    unsigned int shared = WfcUtility_GetLanguage();
    if ((unsigned char)source[5] == 0x79 && shared != 0) {
        return WfcUtilityLocalizeResourcePath_UnknownRoleZeroInitializedStorage;
    }
    WfcUtilityLocalizeResourcePath_UnknownRoleZeroInitializedStorage[5] = WfcUtility_LocalizeResourcePath_TextJefgisk[shared];
    return WfcUtilityLocalizeResourcePath_UnknownRoleZeroInitializedStorage;
}
