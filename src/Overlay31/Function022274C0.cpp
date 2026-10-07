extern "C" volatile unsigned char data_ov031_02250c0c[];

extern "C" void func_ov031_022274c0(unsigned int value)
{
    *reinterpret_cast<volatile unsigned int*>(data_ov031_02250c0c + 0xC) = value;
}
