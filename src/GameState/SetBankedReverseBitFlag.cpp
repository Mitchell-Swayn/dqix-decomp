#pragma thumb off
struct BankedBitFlags {
    unsigned char unknown[0x41b];
    unsigned char flags[2][32];
};
// Original: arm9/main @ 0x0206EA8C; symbol: func_0206ea8c; size: 0x60.
extern "C" void SetBankedReverseBitFlag(BankedBitFlags* object, unsigned char bank, short index, int enabled)
{
    unsigned char oldByte;
    unsigned short bit;
    unsigned char bankIndex;
    short byteIndex;
    unsigned int rawBit = (index & 7) ^ 7;
    bankIndex = bank & 1;
    byteIndex = index >> 3;
    bit = rawBit;
    if (enabled) {
        oldByte = object->flags[bankIndex][byteIndex];
        object->flags[bankIndex][byteIndex] = oldByte | (1 << bit);
    } else {
        oldByte = object->flags[bankIndex][byteIndex];
        object->flags[bankIndex][byteIndex] = oldByte & ~(1 << bit);
    }
}
