extern "C" int func_ov000_021598ec(void* object)
{
    const unsigned char* resource = *(const unsigned char**)((const unsigned char*)object + 0x138);
    unsigned int flags = *(const unsigned int*)(resource + 0x18);
    return (flags & 2) != 0;
}
