#include <globaldefs.h>

extern "C" void TextCache_Construct(void *);
extern "C" void Graphics_InitializeSubOamStagingState(void *);

// Original: arm9/main @ 0x0203C73C; symbol: func_0203c73c; size: 0x20.
extern "C" int TextSprite_ConstructRenderer(char *state) {
    TextCache_Construct(state + 0x10);
    Graphics_InitializeSubOamStagingState(state);
    return (int)state;
}
