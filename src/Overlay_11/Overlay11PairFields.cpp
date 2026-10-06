struct Overlay11PairFields
{
    unsigned char unknown_000[0xb0];
    unsigned int value_b0;
    unsigned int value_b4;
};

extern "C" void func_ov011_02184534(Overlay11PairFields* state,
                                    unsigned int value_b0,
                                    unsigned int value_b4)
{
    state->value_b0 = value_b0;
    state->value_b4 = value_b4;
}
