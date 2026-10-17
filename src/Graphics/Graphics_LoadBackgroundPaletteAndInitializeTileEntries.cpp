#include <globaldefs.h>
#include "System/LoadToVRAM.h"
extern "C" void RenderGlyphBitsIntoCharacterTiles(void*,int,int);
extern "C" void MIi_CpuClearFast(int,void*,unsigned);
extern "C" char data_020ef788[];
extern "C" char data_020ef78b[];
extern "C" char data_020ef78e[];
extern "C" char data_020ef791[];
extern "C" char data_020ef794[];
extern "C" char data_020ef797[];
extern "C" char data_020ef79a[];
extern "C" char data_020e7170[];
extern "C" char data_020fe9cc[];
// Original: arm9/main @ 0x0202AC74; symbol: func_0202ac74; size: 0xBC.
extern "C" ARM void Graphics_LoadBackgroundPaletteAndInitializeTileEntries()
{
    RenderGlyphBitsIntoCharacterTiles(data_020ef788,2,40);
    RenderGlyphBitsIntoCharacterTiles(data_020ef78b,12,48);
    RenderGlyphBitsIntoCharacterTiles(data_020ef78e,1,61);
    RenderGlyphBitsIntoCharacterTiles(data_020ef791,26,65);
    RenderGlyphBitsIntoCharacterTiles(data_020ef794,26,47);
    RenderGlyphBitsIntoCharacterTiles(data_020ef797,1,46);
    RenderGlyphBitsIntoCharacterTiles(data_020ef79a,1,45);
    LoadToMainBGStandardPalette(data_020e7170,0,512);
    MIi_CpuClearFast(0,data_020fe9cc,1536);
}
