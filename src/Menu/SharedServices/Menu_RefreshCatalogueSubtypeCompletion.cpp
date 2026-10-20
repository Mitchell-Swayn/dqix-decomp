#include <globaldefs.h>
ARM
extern "C" void Menu_DisplayCatalogueSubtypeCompletion(void *);
extern "C" void *Menu_FindCatalogueTextCanvasByKey(void *state, unsigned index);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void *, void *);
// Original: arm9/ov004 @ 0x02154718; symbol: func_ov004_02154718; size: 0x30.
extern "C" int Menu_RefreshCatalogueSubtypeCompletion(void *state) {
    Menu_DisplayCatalogueSubtypeCompletion(state);
    void *handle = Menu_FindCatalogueTextCanvasByKey(state, 0x37);
    if (handle != 0)
        MenuTextCanvas_RefreshConfiguredFrameAndContents(handle, state);
    return 0;
}
