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
// Original data: arm9/ov031 @ 0x0224F440; symbol: data_ov031_0224f440.
// Existing shared storage; logical extent and remaining roles are unresolved.
// Original values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char* Aoss_AllocateBuffer(unsigned);
extern "C" void Aoss_FreeBuffer(void*);
extern "C" short BuildPayloadAndOpcode60Records(unsigned char*);
// Original: arm9/ov031 @ 0x0221DCBC; symbol: func_ov031_0221dcbc; size: 0x144.
// Builds a negotiation payload and local.token, submits its request packet, and releases the temporary payload on each path.
extern "C" int WirelessSetup_SendNegotiationRequest(int unused, unsigned char* identifier, int callback)
{
    struct Local { RequestFields fields; unsigned char token[8]; } local;
    local.fields.transform = 0;
    local.fields.length = 0;
    local.fields.flags = 0;
    unsigned char* packet = *(unsigned char**)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x14);
    Memory_FillBufferWithLowByteUsingVectorizedMemset(packet, 0, 0x5dc);
    unsigned char* payload = Aoss_AllocateBuffer(0x210);
    if (!payload) { Aoss_SetLastError(2); return -1; }
    Memory_FillBufferWithLowByteUsingVectorizedMemset(payload, 0, 0x210);
    unsigned char* body = packet + 0x18;
    System_Copy8WithReversedPointers(WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage, identifier, 8);
    System_Copy8WithReversedPointers(local.token, WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage, 8);
    local.fields.length = BuildPayloadAndOpcode60Records(payload + 4);
    if (local.fields.length < 0) { Aoss_SetLastError(3); if (payload) Aoss_FreeBuffer(payload); return -1; }
    payload[0] = 0;
    *(unsigned short*)(payload + 2) = WirelessSetup_EncodeNetworkHalfword((unsigned short)local.fields.length);
    local.fields.length += 4;
    WirelessSetup_CopyOrTransformRequestPayload(0, body, payload, &local.fields.length, (unsigned short*)&local.fields.flags, (unsigned char*)&local.fields.transform);
    local.fields.flags |= 0x10;
    if (WirelessSetup_TransformRequestToken(local.token, 8, WirelessSetup_SendCompletionRequest_TextMELCO, 6)) { Aoss_SetLastError(2); if (payload) Aoss_FreeBuffer(payload); return -1; }
    WirelessSetup_WriteRequestHeader(packet, 0x1000, local.fields.length, local.fields.flags, local.fields.transform, 0x11, local.token);
    local.fields.length += 0x18;
    WirelessSetup_SendRequestDatagram(packet, local.fields.length, 0xff, callback);
    if (payload) Aoss_FreeBuffer(payload);
    return 0;
}
