#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov023 @ 0x021FA598; symbol: func_ov023_021fa598; size: 0x8.
extern "C" void* Menu_GetRecordMessageTable(void* self)
{
    return (char*)self + 0x20;
}
