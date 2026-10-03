#if defined(usa)
extern "C" void func_020407b4(void* object, unsigned int value0,
                               unsigned int value1, unsigned int value2)
{
    unsigned int* fields = reinterpret_cast<unsigned int*>(object);
    fields[0x44 / sizeof(unsigned int)] = value0;
    fields[0x48 / sizeof(unsigned int)] = value1;
    fields[0x4c / sizeof(unsigned int)] = value2;
}
#endif
