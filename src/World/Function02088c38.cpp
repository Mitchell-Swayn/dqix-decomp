struct Function02088c38State
{
    unsigned char unknown_00[0x18];
    unsigned int flags;
    unsigned char unknown_1c[0x50];
    unsigned char state_6c;
    unsigned char unknown_6d[0x22];
    unsigned char state_8f;
};

extern "C" void func_02088c38(Function02088c38State* state)
{
    state->flags &= ~2u;
    state->state_6c = 0;
    state->state_8f = 0;
}
