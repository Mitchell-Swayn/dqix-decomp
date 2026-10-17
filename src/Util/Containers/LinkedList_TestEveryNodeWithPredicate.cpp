#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" int func_0205faf4(int first, int entry, int third);
// Original: arm9/main @ 0x02064704; symbol: func_02064704; size: 0x48.
extern "C" int LinkedList_TestEveryNodeWithPredicate(int first, unsigned char* entry, int third)
{
    while (entry != 0) {
        if (func_0205faf4(first, reinterpret_cast<int>(entry), third) == 0) break;
        entry = *reinterpret_cast<unsigned char**>(entry + 0xc);
    }
    return entry == 0;
}
