// Only the fields touched by this reset routine are known.
struct Function02039ee8State
{
    unsigned short unknown_00;
    unsigned char unknown_02[3];
    unsigned char unknown_05;
    unsigned char unknown_06;
    unsigned char unknown_07;
    unsigned short unknown_08;
};

extern "C" void func_02039ee8(Function02039ee8State* state)
{
    state->unknown_00 = 0;
    state->unknown_05 = 0;
    state->unknown_06 = 0;
    state->unknown_08 = 0;
    state->unknown_07 = 0;
}
