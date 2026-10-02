// Corresponding sub BG0 control register used during title display setup.
extern "C" void func_ov020_0218cd64(unsigned int size, unsigned int colorMode,
    unsigned int screenBase, unsigned int characterBase, unsigned int extendedPalette) {
    volatile unsigned short* control = (volatile unsigned short*)0x04001008;
    *control = (*control & 0x43) | (size << 14) | (colorMode << 7) |
        (screenBase << 8) | (characterBase << 2) | (extendedPalette << 13);
}
