extern "C" void* func_020c01ac(void* records, int index)
{
    if (index < 0)
        return 0;

    unsigned int* words = static_cast<unsigned int*>(records);
    if (static_cast<unsigned int>(index) >= words[7])
        return 0;

    unsigned char* record = static_cast<unsigned char*>(records) + 0x20 + index * 12;
    if (*reinterpret_cast<unsigned int*>(record) == 0xFFFFFFFFu)
        return 0;

    return record;
}
