extern "C" unsigned int data_021142e0;

extern "C" void func_020d404c(unsigned int index, unsigned int value)
{
    unsigned int base = *reinterpret_cast<volatile unsigned int*>(
        reinterpret_cast<unsigned char*>(&data_021142e0) + 4);
    *reinterpret_cast<volatile unsigned int*>(base + index * 4 + 0x18) = value;
}
