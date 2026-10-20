#include <globaldefs.h>
ARM
extern "C" void Menu_DisplayCatalogueKindCompletion(void *);
extern "C" void *Menu_FindCatalogueTextCanvasByKey(void *, unsigned int);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void *, void *);
// Original: arm9/ov004 @ 0x021547FC; symbol: func_ov004_021547fc; size: 0x30.
extern "C" int Object_InitializeAndProcessResolvedType37(void *object) {
    Menu_DisplayCatalogueKindCompletion(object);
    void *resolved = Menu_FindCatalogueTextCanvasByKey(object, 0x37);
    if (resolved)
        MenuTextCanvas_RefreshConfiguredFrameAndContents(resolved, object);
    return 0;
}
