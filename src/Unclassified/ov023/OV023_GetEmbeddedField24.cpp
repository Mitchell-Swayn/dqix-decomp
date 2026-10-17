#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov023 @ 0x021FAD18; symbol: func_ov023_021fad18; size: 0x8.
extern "C" void* OV023_GetEmbeddedField24(void* self)
{
    return (char*)self + 0x24;
}
