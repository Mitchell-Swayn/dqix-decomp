#include <globaldefs.h>
// Original: arm9/main @ 0x0209A93C; symbol: func_0209a93c; size: 0x40.
extern "C" void SpellTable_AppendSpellMapping(int* list, const unsigned short* item)
{
    int base = *list;
    if (base == 0) return;
    int count = *reinterpret_cast<int*>(base + 0x108);
    if (count >= 0x42) return;
    *reinterpret_cast<int*>(base + 0x108) = count + 1;
    base = *list;
    *reinterpret_cast<unsigned short*>(base + (count << 2)) = item[0];
    *reinterpret_cast<unsigned short*>(base + (count << 2) + 2) = item[1];
}
