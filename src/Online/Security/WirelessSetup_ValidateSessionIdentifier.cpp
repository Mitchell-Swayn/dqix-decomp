#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
// Original data: arm9/ov031 @ 0x0224F440; symbol: data_ov031_0224f440.
// Shared zero-initialized request identifier storage; see docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage[];
extern "C" int WirelessSetup_CompareIdentifierBytes(const void*, const void*, unsigned);
// Original: arm9/ov031 @ 0x0221D79C; symbol: func_ov031_0221d79c; size: 0x44.
// Checks a stored six-byte session identifier, allowing an unset identifier only for opcode 0x1000.
extern "C" int WirelessSetup_ValidateSessionIdentifier(int opcode, void* identifier)
{
    int result = 0;
    int i;
    int present;
    const unsigned char* stored = WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage;
    present = 0;
    i = 0;
    for (; i < 6; ++i) {
        if (*stored != 0) {
            present = 1;
            break;
        }
        ++stored;
    }
    if (present) {
        if (WirelessSetup_CompareIdentifierBytes(WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage, identifier, 6)) result = 1;
    } else if (opcode != 0x1000) {
        result = 2;
    }
    return result;
}
