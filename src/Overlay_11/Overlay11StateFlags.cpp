struct Overlay11State
{
    unsigned char unknown_000[0x114];
    unsigned int flags_114;
};

extern "C" void func_ov011_021849ac(Overlay11State* state, unsigned int flags)
{
    state->flags_114 |= flags;
}
