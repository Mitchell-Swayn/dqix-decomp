// Original: arm9/ov025 @ 0x021e169c; symbol: func_ov025_021e169c; size: 0x2c.
extern "C" void ClearMatchingBytesInFixedBuffer(unsigned char* p, unsigned char value) {
    int i=0;
    goto check;
loop:
    if (*p==value) *p=0;
    ++p; ++i;
check:
    if (i<0x51) goto loop;
}
