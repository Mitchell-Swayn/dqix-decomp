// Clear the bits selected by mask in a 32-bit word.
extern "C" void func_020466f4(unsigned int* word, unsigned int mask)
{
    *word &= ~mask;
}
