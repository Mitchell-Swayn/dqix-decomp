#include <globaldefs.h>
ARM
extern "C" void *Menu_GetCharacterPreviewBaseModel(void *);
// Original: arm9/ov023 @ 0x021E4E20; symbol: func_ov023_021e4e20; size: 0x1C.
extern "C" void *Menu_GetActiveCharacterPreviewObject(void *self) {
    void *preview = *(void **)((char *)self + 0x128);
    if (!preview)
        return 0;
    return Menu_GetCharacterPreviewBaseModel(preview);
}
