#pragma thumb off
#pragma force_active on
// Original: arm9/ov017 @ 0x021999B4; symbol: PackFieldsIntoHalfwordAt0400000C; size: 0x2C.
extern "C" void Graphics_ConfigureMainBackgroundTwoControl(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    volatile unsigned short* reg = (volatile unsigned short*)0x0400000C;
    unsigned int value = *reg & 0x43;
    value |= a << 14;
    value |= b << 7;
    value |= c << 8;
    value |= d << 2;
    *reg = (unsigned short)value;
}
