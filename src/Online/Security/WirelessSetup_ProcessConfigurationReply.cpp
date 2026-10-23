#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" void System_Copy8WithReversedPointers(void*, const void*, unsigned);
extern "C" void Memory_FillBufferWithLowByteUsingVectorizedMemset(void*, unsigned, unsigned);
extern "C" unsigned short WirelessSetup_EncodeNetworkHalfword(unsigned short);
extern "C" unsigned WirelessSetup_EncodeNetworkWord(unsigned);
extern "C" unsigned WirelessSetup_DecodeNetworkHalfword(unsigned);
extern "C" unsigned WirelessSetup_DecodeNetworkWord(unsigned);
extern "C" void Aoss_SetLastError(int);
extern "C" int System_CompareEncodedSequenceProgression(const void*, const void*);
extern "C" int Network_ParseSelectedNestedRecordSections(int, unsigned char*, int, unsigned char*, unsigned char*);
// Original data: arm9/ov031 @ 0x0224EDA0; symbol: data_ov031_0224eda0.
// Existing shared storage; logical extent and remaining roles are unresolved.
// Original values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupProcessConfigurationReply_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x0224E720; symbol: data_ov031_0224e720.
// Existing shared storage; logical extent and remaining roles are unresolved.
// Original values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupProcessNegotiationReply_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x0224E6E0; symbol: data_ov031_0224e6e0.
// Existing shared storage; logical extent and remaining roles are unresolved.
// Original values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221D52C; symbol: func_ov031_0221d52c; size: 0xD8.
// Checks a configuration reply, translates remote errors, parses its fields, and accepts a compatible configuration.
extern "C" int WirelessSetup_ProcessConfigurationReply(int status, unsigned char* packet, unsigned* failures, unsigned char* expected)
{
    if (status != 1) { ++*failures; return status; }
    unsigned char* header = packet + 12;
    unsigned char* record = packet + 0x24;
    if (System_CompareEncodedSequenceProgression(expected + 8, header + 16) < 0) { ++*failures; return status; }
    if (!WirelessSetup_DecodeNetworkHalfword(*(unsigned short*)(record + 2))) { ++*failures; return status; }
    if (*record == 7) {
        if ((int)WirelessSetup_DecodeNetworkWord(*(unsigned*)(record + 4)) == -2) Aoss_SetLastError(20);
        else if ((int)WirelessSetup_DecodeNetworkWord(*(unsigned*)(record + 4)) == -3) Aoss_SetLastError(21);
        else Aoss_SetLastError(24);
        return -1;
    }
    Memory_FillBufferWithLowByteUsingVectorizedMemset(WirelessSetupProcessConfigurationReply_UnknownRoleZeroInitializedStorage, 0, 0x6a0);
    if (Network_ParseSelectedNestedRecordSections(0, record, WirelessSetup_DecodeNetworkHalfword(*(unsigned short*)(header + 10)), WirelessSetupProcessConfigurationReply_UnknownRoleZeroInitializedStorage, WirelessSetupProcessNegotiationReply_UnknownRoleZeroInitializedStorage) < 0) { ++*failures; return status; }
    if (!(*(unsigned*)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x30) & *(unsigned*)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x2c))) return status;
    *failures = 0;
    return 2;
}
