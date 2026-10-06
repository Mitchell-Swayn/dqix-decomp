struct Function020965c0Object
{
    unsigned char unknown_[0xac];
    unsigned char values_[0xcc];
};

extern "C" unsigned int func_020965c0(const Function020965c0Object* object,
                                      unsigned int value)
{
    if (value >= 0xcc)
        goto notFound;

    for (int i = 0; i < 0xcc; ++i) {
        if (value == object->values_[i])
            return static_cast<unsigned char>(i);
    }

notFound:
    return 0xff;
}
