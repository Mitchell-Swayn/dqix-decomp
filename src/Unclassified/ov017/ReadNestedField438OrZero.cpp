// Returns nested byte field 0x438, or zero when the pointer at offset 0x24 is null.
// Original: arm9/ov017 @ 0x021B204C; symbol: func_ov017_021b204c; size: 0x14.
extern "C" unsigned int ReadNestedField438OrZero(void* object) {
    void* nested = *(void**)((unsigned char*)object + 0x24);
    if (nested != 0)
        return ((unsigned char*)nested)[0x438];
    return 0;
}
