extern "C" void func_0206df6c(void*, unsigned char* bytes, int bit, int value)
{
    int byte = bit / 8;
    unsigned char* address = bytes + byte;
    unsigned char mask = 1 << (bit % 8);
    unsigned char oldValue = *address;
    *address = value != 0 ? oldValue | mask : oldValue & ~mask;
}
