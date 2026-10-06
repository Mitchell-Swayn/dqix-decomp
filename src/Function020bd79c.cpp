extern "C" unsigned int* volatile data_02110370;

extern "C" unsigned int func_020bd79c(unsigned int index)
{
    unsigned int* object = data_02110370;
    unsigned int* entries = *reinterpret_cast<unsigned int**>(
        reinterpret_cast<unsigned char*>(object) + 0x84);
    const unsigned int count = entries[2];

    if (index >= count) {
        return 0;
    }

    return *reinterpret_cast<unsigned int*>(
        reinterpret_cast<unsigned char*>(entries) + index * 0x10 + 0x10);
}
