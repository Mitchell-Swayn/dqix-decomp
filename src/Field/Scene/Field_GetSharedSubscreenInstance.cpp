#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov017 @ 0x021A193C; symbol: func_ov017_021a193c; size: 0x8.
extern "C" unsigned Field_GetSharedSubscreenInstance(void* self)
{
    return *(unsigned*)((char*)self + 0x1C);
}
