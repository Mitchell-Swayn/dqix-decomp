// Clears the state word in the optional object stored at offset 0x440.
extern "C" void func_02043110(unsigned char* context)
{
    unsigned int object = *reinterpret_cast<unsigned int*>(context + 0x440);
    if (object != 0)
        *reinterpret_cast<unsigned int*>(object + 8) = 0;
}
