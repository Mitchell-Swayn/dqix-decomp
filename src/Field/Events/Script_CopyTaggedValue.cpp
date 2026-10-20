// Original: arm9/ov017 @ 0x021d4a64; symbol: func_ov017_021d4a64; size: 0x14.
extern "C" void Script_CopyTaggedValue(void *dst, const void *src)
{
    *(unsigned int *)dst = *(const unsigned int *)src;
    *(unsigned int *)((char *)dst + 4) = *(const unsigned int *)((const char *)src + 4);
}
