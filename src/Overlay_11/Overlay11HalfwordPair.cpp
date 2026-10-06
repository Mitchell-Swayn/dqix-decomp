struct Overlay11HalfwordPair
{
    unsigned char unknown_000[0x1c4];
    unsigned short first_1c4;
    unsigned short second_1c6;
};

extern "C" void func_ov011_02184bf0(Overlay11HalfwordPair* state,
                                    unsigned int first,
                                    unsigned int second)
{
    state->first_1c4 = (unsigned short)first;
    state->second_1c6 = (unsigned short)second;
}
