// Clears the 32-bit word at record offset 0x4320; the enclosing structure is unknown.
extern "C" {
// Original: arm9/ov017 @ 0x02195540; symbol: func_ov017_02195540; size: 0x10.
void Field_ResetSessionTransitionLatch(unsigned char* record)
{
    *(unsigned int*)(record + 0x4320) = 0;
}
}
