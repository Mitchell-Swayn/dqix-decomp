#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" void System_Copy8WithReversedPointers(void*, const void*, unsigned);
extern "C" unsigned WirelessSetup_GenerateRandomTokenValue();
extern "C" unsigned short WirelessSetup_EncodeNetworkHalfword(unsigned short);
// Original: arm9/ov031 @ 0x0221D354; symbol: func_ov031_0221d354; size: 0x30.
// Initializes eight-byte records with a six-byte identifier and a network-order random token.
extern "C" void WirelessSetup_InitializeRequestTokens(int count, unsigned char* records, const void* identifier)
{
    for (int i = 0; i < count; ++i) {
        System_Copy8WithReversedPointers(records, identifier, 6);
        *(unsigned short*)(records + 6) = WirelessSetup_GenerateRandomTokenValue();
        *(unsigned short*)(records + 6) = WirelessSetup_EncodeNetworkHalfword(*(unsigned short*)(records + 6));
        records += 8;
    }
}
