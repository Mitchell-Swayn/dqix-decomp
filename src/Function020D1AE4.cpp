extern "C" unsigned int func_020d1ae4(unsigned int value)
{
    value = value - ((value >> 1) & 0x55555555u);
    value = (value & 0x33333333u) + ((value >> 2) & 0x33333333u);
    value = (value + (value >> 4)) & 0x0f0f0f0fu;
    value += value >> 8;
    value += value >> 16;
    return value & 0xffu;
}
