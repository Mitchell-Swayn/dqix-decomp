// Original: arm9/ov001 @ 0x021628d4; symbol: func_ov001_021628d4; size: 0x2c
extern "C" void WriteDisplayCaptureControl(unsigned int enable, unsigned int size, unsigned int source, unsigned int destination)
{
    volatile unsigned short* control = (volatile unsigned short*)0x0400100e;
    unsigned int value = *control & 0x43;
    value |= enable << 14;
    value |= size << 7;
    value |= source << 8;
    value |= destination << 2;
    *control = (unsigned short)value;
}
