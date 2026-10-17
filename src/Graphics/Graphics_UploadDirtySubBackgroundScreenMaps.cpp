#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
extern "C" unsigned char data_021065d8[], data_02105fd8[];
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
                    case 0: LoadToSubBG0ScreenData(data_021065d8, zero, 0x1000); break;
                    case 1: LoadToSubBG1ScreenData(data_02105fd8, zero, 0x600); break;
                    }
                    break;
                }
            }
            ++layer;
        }
        ++screen;
    }
}
