// IsNestedOffset4498Byte14Nonzero: describes the directly observed offset-level operation; field roles remain unknown.
// Original: arm9/ov017 @ 0x0218D75C; symbol: func_ov017_0218d75c; size: 0x20.
extern "C" bool Field_HasSpawnedSharedPresentationEffect(void* object)
{
    unsigned char* nested = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x4498);
    return nested != 0 && nested[0x14] != 0;
}
