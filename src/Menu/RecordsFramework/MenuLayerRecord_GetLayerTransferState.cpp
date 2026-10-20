#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov023 @ 0x021F79E4; symbol: func_ov023_021f79e4; size: 0x8.
extern "C" void* MenuLayerRecord_GetLayerTransferState(void* self)
{
    return (char*)self + 0x28;
}
