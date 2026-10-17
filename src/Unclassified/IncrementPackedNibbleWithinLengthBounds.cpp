#include <globaldefs.h>

ARM
extern "C" {
void AppendKeyToGlobalTwentyFourHalfwordHistory(int);
// Original: arm9/main @ 0x0206EC64; symbol: func_0206ec64; size: 0x84.
void IncrementPackedNibbleWithinLengthBounds(unsigned unused, int index, unsigned char *data, unsigned length) {
    int half = index % 2;
    int offset = index / 2;
    if ((unsigned)offset >= length) { AppendKeyToGlobalTwentyFourHalfwordHistory(999); return; }
    unsigned char value = data[offset];
    if (half != 0) {
        unsigned char low = value & 15;
        if (low >= 15) return;
        data[offset] = (unsigned char)(low+1) | (value & 0xf0);
        return;
    }
    unsigned char high = (int)value >> 4;
    if (high < 15) { unsigned char next = high+1; data[offset] = (next << 4) | (value & 15); }
}
}
