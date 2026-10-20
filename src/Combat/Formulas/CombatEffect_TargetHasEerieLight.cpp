// Reads a descriptor field at the evidenced offset and tests the observed value or bit.
// Original: arm9/ov024 @ 0x021df704; symbol: func_ov024_021df704; size: 0x18.
extern "C" bool CombatEffect_TargetHasEerieLight(const void* self)
{
    const unsigned char* descriptor = *reinterpret_cast<const unsigned char* const*>(static_cast<const unsigned char*>(self) + 0x138);
        return (*reinterpret_cast<const unsigned int*>(descriptor + 0x18) & 0x10u) != 0;
}
