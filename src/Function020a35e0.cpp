struct Function020a35e0Record
{
    unsigned char padding[0x34];
    unsigned char flags;
};

extern "C" int func_020a35e0(const Function020a35e0Record* record, unsigned int index)
{
    if (index >= 4)
        return 0;

    return record->flags & (1u << index);
}
