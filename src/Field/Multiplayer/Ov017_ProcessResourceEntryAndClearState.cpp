#include <globaldefs.h>
ARM
extern "C" unsigned char *GameResources_GetInstance(void);
extern "C" void FieldCommandQueue_DrawActiveCommandOverlay(void *resource, int value);
extern "C" void TextLayout_DrawSelectionPanelAndCursor(void *object, unsigned value);
// Original: arm9/ov017 @ 0x021AFA70; symbol: func_ov017_021afa70; size: 0x2C.
extern "C" void Ov017_ProcessResourceEntryAndClearState(unsigned char *self) {
    unsigned char *resources = GameResources_GetInstance() + 0x3000;
    FieldCommandQueue_DrawActiveCommandOverlay(*(void **)(resources + 0x700), *(int *)(self + 4));
    TextLayout_DrawSelectionPanelAndCursor(self + 0x48, 0);
}
