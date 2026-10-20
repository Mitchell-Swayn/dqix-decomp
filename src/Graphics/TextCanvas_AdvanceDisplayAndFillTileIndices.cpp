#include <globaldefs.h>

extern "C" void TextCanvas_AdvanceDisplayState(void*, int);
extern "C" void TextCanvas_FillSequentialCharacterTilemap(void*);

// Original: arm9/main @ 0x0204C964; symbol: func_0204c964; size: 0x1C.
extern "C" ARM void TextCanvas_AdvanceDisplayAndFillTileIndices(void* object) {
    TextCanvas_AdvanceDisplayState(object, 1);
    TextCanvas_FillSequentialCharacterTilemap(object);
}
