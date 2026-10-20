#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02239EE0; symbol: Network_SelectSetMaskPosition; size: 0xE8.
extern "C" int Network_SelectSetMaskPosition(unsigned mask) {
    short only_position = 0;
    unsigned short count = 0;
    short bit_index = 0;
    while (bit_index < 16) {
        if (mask & (1u << bit_index)) { only_position = (short)(bit_index + 1); ++count; }
        bit_index = (short)(bit_index + 1);
    }
    if (count <= 1) return only_position;
    volatile unsigned* state = *(unsigned**)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4);
    unsigned seed = state[0x58 / 4] * 0x10dcd + 0x3039;
    state[0x58 / 4] = seed;
    unsigned product = count * ((*(volatile unsigned**)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4))[0x58 / 4] & 0xff);
    unsigned rank = (product << 8) >> 16;
    short position = 0;
    do {
        if (mask & 1) {
            if (rank == 0) return (short)(position + 1);
            rank = (rank - 1) << 16 >> 16;
        }
        mask = (mask << 15) >> 16;
        position = (short)(position + 1);
    } while (position < 16);
    return 0;
}
