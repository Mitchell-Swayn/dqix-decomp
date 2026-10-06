extern "C" void func_ov017_021a55a4(void* object, unsigned char first, unsigned char second)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    bytes[0x20] = first;
    bytes[0x21] = second;
}
