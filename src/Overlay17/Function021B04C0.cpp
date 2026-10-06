extern "C" int func_ov017_021b04c0(void* object)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int state = *reinterpret_cast<unsigned int*>(bytes + 0x28);

    if (state != 0)
    {
        bytes[0x21] = 0;
        bytes[0x22] = 0;
        return 7;
    }

    return bytes[0x0a];
}
