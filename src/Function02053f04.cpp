#include "System/Matrix.h"

extern "C" void* __clear(void* destination, unsigned int count);
extern unsigned int data_020f0420[];

// Only the portion accessed here is known. Keep the surrounding object opaque.
struct Function02053f04State
{
    unsigned char unknown_000[0x15c];
    unsigned int value_15c;
    Vector3i vector_160;
    Vector3i vector_16c;
};

extern "C" void func_02053f04(Function02053f04State* state)
{
    Vector3i zero;
    __clear(&zero, sizeof(zero));

    state->value_15c = data_020f0420[1];
    state->vector_160 = zero;
    state->vector_16c = zero;
}
