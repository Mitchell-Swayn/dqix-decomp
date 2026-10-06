struct Overlay11HalfwordFields
{
    unsigned char unknown_000[0x1c0];
    unsigned short first_1c0;
    unsigned short second_1c2;
};

extern "C" void func_ov011_02184be0(Overlay11HalfwordFields* state,
                                    unsigned int first,
                                    unsigned int second)
{
    state->first_1c0 = (unsigned short)first;
    state->second_1c2 = (unsigned short)second;
}
