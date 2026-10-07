extern "C" unsigned int func_0205b174(unsigned int, const void* object)
{
    if (object == 0)
        return 0;

    const unsigned char* bytes = static_cast<const unsigned char*>(object);
    const unsigned int field = *reinterpret_cast<const unsigned int*>(bytes + 4);
    const unsigned int value = *reinterpret_cast<const unsigned short*>(field);
    return (value >> 10) & 3;
}
