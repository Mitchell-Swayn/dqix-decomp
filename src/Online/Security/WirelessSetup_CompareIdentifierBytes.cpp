#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
// Original: arm9/ov031 @ 0x0221E4FC; symbol: func_ov031_0221e4fc; size: 0x20.
// Compares unsigned identifier bytes, stopping at the first difference or signed length limit.
extern "C" int WirelessSetup_CompareIdentifierBytes(const void* first, const void* second, unsigned length)
{
    const unsigned char* a = (const unsigned char*)first;
    const unsigned char* b = (const unsigned char*)second;
    int difference = 0;
    while ((int)length-- > 0 && (difference = *a - *b) == 0) {
        ++a;
        ++b;
    }
    return difference;
}
