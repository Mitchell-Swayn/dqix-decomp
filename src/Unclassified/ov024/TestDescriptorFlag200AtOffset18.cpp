// Reads a descriptor field at the evidenced offset and tests the observed value or bit.
// Original: arm9/ov024 @ 0x021eadfc; symbol: func_ov024_021eadfc; size: 0x18.
extern "C" bool TestDescriptorFlag200AtOffset18(const void* self)
{
    const unsigned char* descriptor = *reinterpret_cast<const unsigned char* const*>(static_cast<const unsigned char*>(self) + 0x138);
        return (*reinterpret_cast<const unsigned int*>(descriptor + 0x18) & 0x200u) != 0;
}
