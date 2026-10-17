// Stores one to the word field at offset 0x4320 from the supplied base.
// Original: arm9/ov017 @ 0x02195530; symbol: func_ov017_02195530; size: 0x10.
extern "C" void SetWordField320ToOne(void* object) {
    *(volatile unsigned int*)((unsigned char*)object + 0x4320) = 1;
}
