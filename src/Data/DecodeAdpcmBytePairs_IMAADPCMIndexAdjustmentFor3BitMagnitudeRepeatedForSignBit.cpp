#include <globaldefs.h>
// IMA ADPCM index adjustment for 3-bit magnitude, repeated for sign bit.
extern "C" {
// Original data: arm9/ov016 @ 0x219cee0; symbol: data_ov016_0219cee0.
// IMA ADPCM index adjustment for 3-bit magnitude, repeated for sign bit.
// Initial values: hex ffffffff02040608ffffffff02040608.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern const signed char DecodeAdpcmBytePairs_IMAADPCMIndexAdjustmentFor3BitMagnitudeRepeatedForSignBit[16] = {
    -1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8,
};
}
