extern "C" unsigned short func_0202df58();

extern "C" bool func_0202c508(const unsigned int* value)
{
    int nonzero = *value != 0;
    if (!nonzero)
        return true;
    return func_0202df58() == 0;
}
