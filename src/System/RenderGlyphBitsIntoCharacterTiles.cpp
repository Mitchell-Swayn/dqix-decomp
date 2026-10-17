#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
struct GlyphKey { signed char bytes[3]; };
extern "C" {
void __clear(void *, unsigned);
const unsigned char *TextLookup_FindKeyInPrimaryThenFallbackResource(int, GlyphKey *);
extern unsigned char data_020fe9ac[32];
}
// Original: arm9/main @ 0x0202AB34; symbol: func_0202ab34; size: 0x140.
extern "C" void RenderGlyphBitsIntoCharacterTiles(const void *key,int count,unsigned tile) {
    GlyphKey current;
    __clear(&current,3);
    memcpy(&current,key,2);
    for (int i = 0; i < count; ++i) {
        const unsigned char *bits = TextLookup_FindKeyInPrimaryThenFallbackResource(8,&current);
        if (bits) {
            unsigned char *dest = data_020fe9ac;
            memset(dest,0,32);
            unsigned bit = 0;
            for (short row = 0; row < 8;) {
                for (short col = 0; col < 8; ++col) {
                    if (*bits & (1 << bit)) {
                        if (col & 1) {
                            dest[col >> 1] = (dest[col >> 1] & 15) | 16;
                        } else {
                            dest[col >> 1] &= 0xf0;
                            dest[col >> 1] |= 1;
                        }
                    }
                    if ((int)++bit >= 8) { bit = 0; ++bits; }
                }
                ++row;
                dest += 4;
            }
            CleanInvalidateCacheRange(data_020fe9ac,32);
            LoadToMainBG1CharacterData(data_020fe9ac,tile << 5,32);
            CleanCacheRange(data_020fe9ac,32);
        }
        tile = (tile + 1) & 255;
        ++current.bytes[1];
    }
}
