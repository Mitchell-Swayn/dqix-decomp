extern "C" void func_ov017_021d4a24(void* object)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    *reinterpret_cast<unsigned int*>(bytes + 0x3c) = 0;
    *reinterpret_cast<unsigned int*>(bytes + 0x40) = 0;
    *reinterpret_cast<unsigned int*>(bytes + 0x44) = 0;
}
