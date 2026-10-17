#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov017 @ 0x021B8470; symbol: func_ov017_021b8470; size: 0x8.
extern "C" unsigned OV017_ReadWordField6B0(void* self)
{
    return *(unsigned*)((char*)self + 0x6B0);
}
