extern "C" unsigned int* volatile data_02110370;

extern "C" void func_020bd8d4(unsigned int index, unsigned int value)
{
    unsigned int* object = data_02110370;
    unsigned int* entries = *reinterpret_cast<unsigned int**>(
        reinterpret_cast<unsigned char*>(object) + 0x84);

    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<unsigned char*>(entries) + index * 0x10 + 0x14) = value;
}
