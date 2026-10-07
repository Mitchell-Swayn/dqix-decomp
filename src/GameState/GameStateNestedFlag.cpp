struct NestedFlagState {
    unsigned char padding[0x14];
    unsigned int flag;
};

struct NestedFlagRoot {
    unsigned char padding[0x138];
    NestedFlagState* nested;
};

extern "C" int func_02010088(NestedFlagRoot* state)
{
    unsigned int flag = state->nested->flag;
    if (flag & 1)
        return 1;
    return 0;
}
