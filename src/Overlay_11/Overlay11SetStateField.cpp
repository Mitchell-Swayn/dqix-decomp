struct Overlay11StateField
{
    unsigned char unknown_000[0x1c8];
    unsigned int value_1c8;
};

extern "C" void func_ov011_02184ad8(Overlay11StateField* state)
{
    state->value_1c8 = 1;
}
