#include <globaldefs.h>
extern "C" int Font_MapCharacterInRange(unsigned short* context);
// Original: arm9/main @ 0x020B0E6C; symbol: func_020b0e6c; size: 0x48.
extern "C" unsigned int Font_FindGlyphIndexForCharacter(unsigned int** root, unsigned int key)
{
    unsigned short* node = reinterpret_cast<unsigned short*>(root[0][4]);
    if (node == 0) goto not_found;
loop:
    if (node[0] <= key && key <= node[1]) return static_cast<unsigned int>(Font_MapCharacterInRange(node));
    node = *reinterpret_cast<unsigned short**>(node + 4);
    if (node != 0) goto loop;
not_found:
    return 0xffff;
}
