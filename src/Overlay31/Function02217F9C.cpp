extern "C" unsigned int func_ov031_02204c84(unsigned int value);

extern "C" unsigned int func_ov031_02217f9c(const void* object)
{
    unsigned int value = *(const unsigned int*)((const unsigned char*)object + 0x1124);
    return func_ov031_02204c84(value);
}
