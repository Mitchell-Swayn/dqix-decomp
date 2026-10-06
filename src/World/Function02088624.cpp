struct Function02088624State
{
    unsigned char unknown_000[0x14];
    unsigned int flags_014;
    unsigned char unknown_018[0x0a];
    unsigned short mode_022;
};

extern "C" void func_02088624(Function02088624State* state)
{
    state->flags_014 |= 2;
    state->mode_022 = (state->mode_022 & ~3u) | 1u;
}
