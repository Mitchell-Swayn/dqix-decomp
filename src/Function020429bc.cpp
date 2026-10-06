// The surrounding state object is only partially understood. This accessor
// exposes its pointer-sized field at offset 0x10 for selector 8.
struct Function020429bcState
{
    unsigned char unknown_000[0x10];
    void* value_010;
};

extern "C" Function020429bcState data_02107800;

extern "C" void* func_020429bc(unsigned int selector)
{
    void* value = 0;
    if (selector == 8)
        value = data_02107800.value_010;
    return value;
}
