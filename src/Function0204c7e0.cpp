// Return whether the second object reference is present, provided the first is.
extern "C" int func_0204c7e0(const void* object)
{
    const unsigned char* bytes = static_cast<const unsigned char*>(object);
    if (*reinterpret_cast<const unsigned int*>(bytes + 0xd4) == 0)
        return 0;

    return *reinterpret_cast<const unsigned int*>(bytes + 0x9c) != 0;
}
