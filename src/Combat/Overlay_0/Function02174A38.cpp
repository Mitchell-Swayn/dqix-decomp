extern "C" void func_ov000_02174a38(void* object, int enabled)
{
    unsigned char* flags = (unsigned char*)object + 0x24;

    if (enabled)
        *flags |= 4;
    else
        *flags &= ~4;
}
