// The stores identify widths and offsets, but not this record's owner or meaning.
struct UnknownResetRecord
{
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    unsigned char unknown_14;
    unsigned char padding_15[3];
    int unknown_18;
    unsigned char unknown_1c;
    unsigned char unknown_1d;
    unsigned char padding_1e[2];
};

extern "C" void func_0201f9b8(UnknownResetRecord* state)
{
    state->unknown_00 = -1;
    state->unknown_04 = -1;
    state->unknown_08 = -1;
    state->unknown_0c = -1;
    state->unknown_10 = 0;
    state->unknown_14 = 0;
    state->unknown_18 = 0;
    state->unknown_1c = 0;
    state->unknown_1d = 0;
}
