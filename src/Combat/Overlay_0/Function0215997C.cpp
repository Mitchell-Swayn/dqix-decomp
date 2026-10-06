extern "C" int func_ov000_0215997c(void* object)
{
    const unsigned char* resource = *(const unsigned char**)((const unsigned char*)object + 0x138);
    unsigned int flags = *(const unsigned int*)(resource + 0x14);
    return (flags & 0x4000) != 0;
}
