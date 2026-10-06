// Only the field read by this accessor is known; the rest of the object remains opaque.
struct Function020421a0State
{
    unsigned char unknown_000[0x1c];
    void* value_01c;
};

extern "C" Function020421a0State data_02107800;

extern "C" void* func_020421a0()
{
    return data_02107800.value_01c;
}
