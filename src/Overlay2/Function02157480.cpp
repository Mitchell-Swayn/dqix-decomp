extern "C" void func_ov002_02157480(void* object, int* values)
{
    if (values == 0)
        return;

    for (int i = 0; i < 4; i++)
        values[i] = -1;

    signed char* bytes = (signed char*)object;
    for (int i = 0; i < bytes[0x1c73]; i++) {
        signed char* entry = bytes + i;
        values[i] = entry[0x1c6e];
    }
}
