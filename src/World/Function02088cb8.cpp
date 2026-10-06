struct Function02088cb8State
{
    unsigned char unknown_00[0x14];
    unsigned int flags;
};

extern "C" bool func_02088cb8(const Function02088cb8State* state)
{
    return (state->flags & 1) == 0;
}
