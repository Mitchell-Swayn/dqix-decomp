struct Function020a2cc4Object
{
    unsigned char unknown_000[0x245];
    unsigned char flags_245;
};

extern "C" int func_020a2cc4(const Function020a2cc4Object* object)
{
    return (object->flags_245 & 2) != 0;
}
