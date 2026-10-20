#include "std_library_functions.h"

// Original data: arm9/main @ 0x20eef30; symbol: data_020eef30.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" uint32_t Rand_UnknownRoleInitializedBytes = 1;

// Original: arm9/main @ 0x02003D14; symbol: rand; size: 0x34.
int rand()
{
    Rand_UnknownRoleInitializedBytes = Rand_UnknownRoleInitializedBytes * 0x41c64e6d + 12345;
    return (Rand_UnknownRoleInitializedBytes >> 16) & 0x7fff;
}

// Original: arm9/main @ 0x02003D48; symbol: srand; size: 0x10.
void srand(int seed)
{
    Rand_UnknownRoleInitializedBytes = seed;
}
