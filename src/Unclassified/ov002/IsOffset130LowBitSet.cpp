// Reads the low bit of the word reached through the pointer stored at object offset 0x130.
// Original: arm9/ov002 @ 0x0216364C; symbol: func_ov002_0216364c; size: 0x18.
extern "C" bool IsOffset130LowBitSet(void* object)
{
    unsigned int* nested = *reinterpret_cast<unsigned int**>(static_cast<unsigned char*>(object) + 0x130);
    return (*nested & 1u) != 0;
}
