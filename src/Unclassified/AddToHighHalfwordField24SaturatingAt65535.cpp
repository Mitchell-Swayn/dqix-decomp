#pragma optimize_for_size off
// Original: arm9/main @ 0x020A0644; symbol: func_020a0644; size: 0x30.
extern "C" void AddToHighHalfwordField24SaturatingAt65535(unsigned char* object, unsigned int amount)
{
    volatile unsigned int* state = (volatile unsigned int*)(object + 0x24);
    unsigned int value = amount + (*state >> 16);
    if (value > 0xffff) value = 0xffff;
    unsigned int upper = value << 16;
    unsigned int lower = *state & 0xffff;
    *state = upper | lower;
}
