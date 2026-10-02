#pragma optimize_for_size off

extern "C" void func_0200d8bc();

extern "C" void func_0200f368()
{
    func_0200d8bc();
}
extern "C" void* __clear(void* destination, unsigned int count)
{
    char* cursor = (char*)destination;
    if (!cursor || !count)
        return destination;
    do {
        *cursor++ = 0;
    } while (--count);
    return destination;
}
