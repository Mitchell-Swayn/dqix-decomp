#include <globaldefs.h>
ARM
extern "C" struct AllowedValues { int value[3]; };
// Original data: arm9/ov004 @ 0x216fa80; symbol: data_ov004_0216fa80.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3200000033000000ffffffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" AllowedValues ProcessAllowedResolvedHandles_UnknownRoleInitializedBytes;
extern "C" void Menu_RebuildCatalogueFilteredList(void*);
extern "C" void* Menu_FindCatalogueTextCanvasByKey(void*, unsigned);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*, void*);
// Original: arm9/ov004 @ 0x02154984; symbol: func_ov004_02154984; size: 0x60.
extern "C" int ProcessAllowedResolvedHandles(void* state) {
    Menu_RebuildCatalogueFilteredList(state);
    AllowedValues values = ProcessAllowedResolvedHandles_UnknownRoleInitializedBytes;
    for (int i = 0; values.value[i] >= 0;) {
        void* handle = Menu_FindCatalogueTextCanvasByKey(state, values.value[i]);
        if (handle != 0) {
            MenuTextCanvas_RefreshConfiguredFrameAndContents(handle, state);
            ++i;
        }
    }
    return 0;
}
