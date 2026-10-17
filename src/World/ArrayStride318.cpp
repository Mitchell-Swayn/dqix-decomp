// Original: arm9/main @ 0x02028BAC; symbol: func_02028bac; size: 0x24.
extern "C" void* GetBoundedEntryAtStride318(void* base, int index)
{
    if (index < 0 || index >= 4) return 0;
    return (char*)base + index * 0x318;
}
