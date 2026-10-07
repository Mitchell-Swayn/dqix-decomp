extern "C" void func_020bc210(void* volatile* object, unsigned short first,
                               unsigned short second)
{
    if (*object == 0) {
        return;
    }

    *(volatile unsigned short*)((unsigned char*)*object + 0x34) = 2;
    *(volatile unsigned short*)((unsigned char*)*object + 0x38) = first;
    *(volatile unsigned short*)((unsigned char*)*object + 0x3a) = second;
}
