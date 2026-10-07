extern "C" int func_020d8550(int value)
{
    const int byte = value & 0xff;
    int isUpper = 0;
    if (byte >= 'A')
        isUpper = byte <= 'Z';

    if (isUpper != 0)
        value += 0x20;

    return static_cast<signed char>(value);
}
