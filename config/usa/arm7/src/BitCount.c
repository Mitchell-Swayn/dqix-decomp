/* Count bits in parallel: first pairs, then nibbles, bytes, and the whole word.
 * Unsigned arithmetic supplies the logical shifts used by the original code. */
unsigned int ARM7_CountSetBits(unsigned int value) {
    value -= (value >> 1) & 0x55555555;
    value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
    value = (value + (value >> 4)) & 0x0f0f0f0f;
    value += value >> 8;
    value += value >> 16;
    return value & 0xff;
}
