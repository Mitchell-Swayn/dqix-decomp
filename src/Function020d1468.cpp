extern "C" void func_020d1468(unsigned int* output)
{
    volatile unsigned short* keyInput =
        (volatile unsigned short*)0x04000204;

    output[0] = (*keyInput & 0x000c) >> 2;
    output[1] = (*keyInput & 0x0010) >> 4;

    unsigned short value = *keyInput;
    *keyInput = (value & ~0x000c) | 0x000c;

    value = *keyInput;
    *keyInput = value & ~0x0010;
}
