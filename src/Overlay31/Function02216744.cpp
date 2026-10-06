extern "C" unsigned char data_ov031_0224e5dc[];

extern "C" void func_ov031_02216744()
{
    volatile unsigned int* const base =
        reinterpret_cast<volatile unsigned int*>(data_ov031_0224e5dc);
    base[2] = 2;
}
