extern "C" bool func_ov017_021b8b54(void* object)
{
    const unsigned char* bytes = static_cast<const unsigned char*>(object);
    const volatile unsigned short* field = reinterpret_cast<const volatile unsigned short*>(bytes + 0x6b4);
    return *field == 0;
}
