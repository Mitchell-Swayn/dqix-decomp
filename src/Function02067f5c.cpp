extern "C" void func_02067f5c(signed char* text, int length)
{
    if (text == 0) {
        return;
    }

    int count = 0;
    while (count < length) {
        int value = *text;
        if (value == 0) {
            return;
        }
        if (value >= 0x61 && value <= 0x7a) {
            value -= 0x20;
        }
        *text++ = (signed char)value;
        ++count;
    }
}
