#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" const void* WirelessSetup_ValidateMessageChecksum(const void*, unsigned*, unsigned*);
extern "C" int Crypto_UnwrapAesKey(void*, const void*, unsigned, const void*, unsigned);
#pragma thumb off
extern "C" void* memcpy(void*, const void*, unsigned);
#pragma thumb on
// Original: arm9/ov031 @ 0x022204EC; symbol: func_ov031_022204ec; size: 0x50.
// Validates message type and checksum, then copies or AES-unwraps its payload and returns its length.
extern "C" unsigned WirelessSetup_ExtractMessagePayload(const void* message, unsigned expectedType, void* output, const void* key)
{
    unsigned type;
    unsigned length;
    const void* payload = WirelessSetup_ValidateMessageChecksum(message, &type, &length);
    if (!payload) return 0;
    if (type != expectedType) return 0;
    if (key) {
        Crypto_UnwrapAesKey(output, payload, length, key, 16);
        length -= 8;
    } else {
        memcpy(output, payload, length);
    }
    return length;
}
