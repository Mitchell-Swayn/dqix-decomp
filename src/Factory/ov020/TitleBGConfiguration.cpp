// Configure the title's main BG1 control register. Priority and
// mosaic bits are preserved; all other BG control fields come from arguments.
extern "C" void func_ov020_0218c7bc(unsigned int size, unsigned int colorMode,
    unsigned int screenBase, unsigned int characterBase, unsigned int extendedPalette) {
    volatile unsigned short* control = (volatile unsigned short*)0x0400000a;
    *control = (*control & 0x43) | (size << 14) | (colorMode << 7) |
        (screenBase << 8) | (characterBase << 2) | (extendedPalette << 13);
}
