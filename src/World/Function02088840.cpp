struct UnknownFlagState
{
    unsigned char unknown_00[0x14];
    unsigned int flags;
};

extern "C" bool func_02088840(const UnknownFlagState* state)
{
    return (state->flags & 1) == 0;
}
