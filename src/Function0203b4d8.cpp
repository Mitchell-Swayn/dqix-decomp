// Set bits in the word at offset four of the caller-owned flags structure.
extern "C" void func_0203b4d8(void* object, unsigned int flags)
{
    unsigned int* word = reinterpret_cast<unsigned int*>(
        static_cast<unsigned char*>(object) + 4);
    *word |= flags;
}
