extern "C"
{
    extern unsigned short data_020f226c;
    extern volatile unsigned short data_02111220;
}

extern "C" void func_020c391c(int value, int displayBits, int displayMode)
{
    volatile unsigned int* displayControl = (volatile unsigned int*)0x04000000;

    unsigned short state = data_020f226c;
    unsigned int currentControl = *displayControl;
    data_02111220 = value;
    if (state == 0)
        value = 0;

    *displayControl = (currentControl & 0xFFF0FFF0) |
                      (value << 16) | displayBits | (displayMode << 3);

    if (data_02111220 == 0)
        data_020f226c = 0;
}
