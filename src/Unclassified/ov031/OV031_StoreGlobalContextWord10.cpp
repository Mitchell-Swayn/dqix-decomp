#pragma thumb on
#pragma force_active on
extern "C" char data_ov031_0224e6e0[];
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov031 @ 0x0221D060; symbol: func_ov031_0221d060; size: 0xC.
extern "C" void OV031_StoreGlobalContextWord10(unsigned value)
{
    *(unsigned*)(data_ov031_0224e6e0 + 0x10) = value;
}
