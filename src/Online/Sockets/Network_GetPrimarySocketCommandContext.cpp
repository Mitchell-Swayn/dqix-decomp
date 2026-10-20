#pragma thumb off
struct PointerPairAt64 {
    unsigned char padding[0x64];
    void* primary;
    void* fallback;
};
// Reads the pointer at offset 0x64, falling back to offset 0x68 when it is null.
// Original: arm9/ov031 @ 0x02205194; symbol: func_ov031_02205194; size: 0x14.
extern "C" void* Network_GetPrimarySocketCommandContext(PointerPairAt64* object)
{
    return object->primary != 0 ? object->primary : object->fallback;
}
