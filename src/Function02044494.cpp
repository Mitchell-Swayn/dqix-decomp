extern "C" void* memcpy(void* destination, const void* source, unsigned int count);

extern "C" bool func_02044494(const void* unused, const void* value)
{
    unsigned short word;
    memcpy(&word, value, sizeof(word));
    return (word & 0xff00) == 0xff00;
}
