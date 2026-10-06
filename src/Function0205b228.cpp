extern "C" void func_0205b228(unsigned char* object, unsigned int value,
                               unsigned char flag)
{
    *reinterpret_cast<unsigned int*>(object + 4) = value;
    object[8] = flag;
}
