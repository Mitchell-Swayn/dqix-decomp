#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" int WirelessSetup_EncodePrefixedPayload(unsigned char*, unsigned char*, int, unsigned char*, void*, void*, int);
extern "C" unsigned short WirelessSetup_EncodeNetworkHalfword(unsigned short);
extern "C" void System_Copy8WithReversedPointers(void*, const void*, unsigned);
// Original data: arm9/ov031 @ 0x0224F440; symbol: data_ov031_0224f440.
// Shared zero-initialized request identifier storage; see docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221DFD4; symbol: func_ov031_0221dfd4; size: 0x54.
// Copies a request payload or adds a network-order length and transformed prefix, updating the caller length.
extern "C" void WirelessSetup_CopyOrTransformRequestPayload(int mode, unsigned char* output, unsigned char* input, short* length, unsigned short* flag, unsigned char* transformFlag)
{
    if (mode == 1) {
        *flag = 1;
        WirelessSetup_EncodePrefixedPayload(input, output + 4, *length, transformFlag, output + 2, WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage, 8);
        *(unsigned short*)output = WirelessSetup_EncodeNetworkHalfword((unsigned short)*length);
        *length += 4;
    } else {
        System_Copy8WithReversedPointers(output, input, *length);
    }
}
