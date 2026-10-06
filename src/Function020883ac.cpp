struct Function020883acObject
{
    unsigned char unknown_000[0x14];
    unsigned int flags_014;
};

extern "C" int func_020883ac(const Function020883acObject* object)
{
    const unsigned int flags = object->flags_014;
    if ((flags & 1) != 0)
        return 0;

    return (flags & 0x01000000) == 0;
}
