extern "C" void _ZN8Object3D4DrawEb(void* object, bool update);

extern "C" void func_ov008_02184918(void* object)
{
    const signed char state = *((signed char*)object + 0xb10);
    if (state == 0 || state == 0xe)
        return;

    if ((*((unsigned int*)object + 0x2c6) & 0x80) != 0)
        return;

    *(volatile unsigned int*)0x04000444 = 0;
    _ZN8Object3D4DrawEb((unsigned char*)object + 0x790, false);
    *(volatile unsigned int*)0x04000448 = 1;
}
