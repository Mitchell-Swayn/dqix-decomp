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
// Original data: arm9/ov031 @ 0x0224E6E0; symbol: data_ov031_0224e6e0.
// Existing shared storage; logical extent and remaining roles are unresolved.
// Original values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x0224B0DC; symbol: data_ov031_0224b0dc.
// Existing shared storage; logical extent and remaining roles are unresolved.
// Original values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetup_SendCompletionRequest_TextMELCO[];
struct RequestFields {
    signed char transform;
    unsigned char unused;
    short flags;
    short length;
};
extern "C" void WirelessSetup_CopyOrTransformRequestPayload(int, unsigned char*, unsigned char*, short*, unsigned short*, unsigned char*);
extern "C" int WirelessSetup_TransformRequestToken(void*, unsigned, const void*, unsigned);
extern "C" void WirelessSetup_WriteRequestHeader(void*, int, int, int, int, int, const void*);
extern "C" void WirelessSetup_SendRequestDatagram(void*, int, int, int);
// Original: arm9/ov031 @ 0x0221DE00; symbol: func_ov031_0221de00; size: 0xDC.
// Builds and transforms a configuration request, writes its header, and sends the packet.
extern "C" int WirelessSetup_SendConfigurationRequest(int unused, unsigned char* identifier, int callback)
{
    struct Local { RequestFields fields; unsigned short padding; unsigned char payload[8]; unsigned char token[8]; } local;
    local.fields.transform = 0;
    local.fields.length = 0;
    local.fields.flags = 0;
    unsigned char* packet = *(unsigned char**)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x14);
    Memory_FillBufferWithLowByteUsingVectorizedMemset(local.payload, 0, 8);
    Memory_FillBufferWithLowByteUsingVectorizedMemset(packet, 0, 0x5dc);
    local.payload[0] = 2;
    local.payload[1] = 0;
    *(unsigned short*)(local.payload + 2) = WirelessSetup_EncodeNetworkHalfword(4);
    *(unsigned*)(local.payload + 4) = *(unsigned*)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x2c);
    *(unsigned*)(local.payload + 4) = WirelessSetup_EncodeNetworkWord(*(unsigned*)(local.payload + 4));
    local.fields.length = 8;
    WirelessSetup_CopyOrTransformRequestPayload(*(int*)AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage, packet + 0x18, local.payload, &local.fields.length, (unsigned short*)&local.fields.flags, (unsigned char*)&local.fields.transform);
    identifier += 8;
    System_Copy8WithReversedPointers(local.token, identifier, 8);
    if (WirelessSetup_TransformRequestToken(local.token, 8, WirelessSetup_SendCompletionRequest_TextMELCO, 6)) { Aoss_SetLastError(2); return -1; }
    WirelessSetup_WriteRequestHeader(packet, 0x2000, local.fields.length, local.fields.flags, local.fields.transform, 0x11, local.token);
    local.fields.length += 0x18;
    WirelessSetup_SendRequestDatagram(packet, local.fields.length, 0, callback);
    return 0;
}
