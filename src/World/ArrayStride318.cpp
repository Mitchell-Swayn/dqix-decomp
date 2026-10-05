extern "C" void* func_02028bac(void* base, int index)
{
    if (index < 0 || index >= 4) return 0;
    return (char*)base + index * 0x318;
}
