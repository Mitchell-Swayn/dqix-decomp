#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
// Original data: arm9/main @ 0x2105fd8; symbol: data_02105fd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21065d8; symbol: data_021065d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4096 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2[], GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage[];
struct BackgroundScreenState { unsigned reserved[16]; int dirty[8]; };
// Original: arm9/main @ 0x0203BA74; symbol: func_0203ba74; size: 0xA8.
// Clears dirty flags for both screen banks and uploads changed sub BG0/BG1 maps.
extern "C" void Graphics_UploadDirtySubBackgroundScreenMaps(BackgroundScreenState* state)
{
    int screen = 0;
    const unsigned zero = 0;
    int layer;
    while (screen < 2) {
        layer = 0;
        while (layer < 4) {
            int dirtyValue = state->dirty[layer + screen * 4];
            if (dirtyValue) {
                state->dirty[layer + screen * 4] = 0;
                switch (screen) { case 1:
                    switch (layer) {
                    case 0: LoadToSubBG0ScreenData(GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2, zero, 0x1000); break;
                    case 1: LoadToSubBG1ScreenData(GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage, zero, 0x600); break;
                    }
                    break;
                }
            }
            ++layer;
        }
        ++screen;
    }
}
