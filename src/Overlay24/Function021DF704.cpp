extern "C" int func_ov024_021df704(void* object)
{
    void* state = *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x138);
    unsigned int flags = *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(state) + 0x18);
    return (flags & 0x10) != 0;
}
