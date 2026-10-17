#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov023 @ 0x021F6BB0; symbol: func_ov023_021f6bb0; size: 0x8.
extern "C" void OV023_WriteWordField04(void* self, unsigned value)
{
    *(unsigned*)((char*)self + 4) = value;
}
