struct Function0204936cInner
{
    unsigned char unknown_000[0x20];
    unsigned int flags_020;
};

struct Function0204936cObject
{
    unsigned char unknown_000[0x13c];
    Function0204936cInner* inner_13c;
};

extern "C" int func_0204936c(const Function0204936cObject* object)
{
    if (object->inner_13c == 0)
        return 0;

    return (object->inner_13c->flags_020 & 0x10) != 0;
}
