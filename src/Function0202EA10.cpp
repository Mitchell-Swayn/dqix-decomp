extern "C" void func_0202ea10(void* object, unsigned int value, unsigned int enabled)
{
    if (enabled != 0)
    {
        unsigned char* bytes = static_cast<unsigned char*>(object);
        *reinterpret_cast<unsigned int*>(bytes + 0x1e4) = value;
        *reinterpret_cast<unsigned int*>(bytes + 0x1e8) = enabled;
    }
}
