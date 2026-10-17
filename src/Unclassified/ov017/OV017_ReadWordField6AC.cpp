#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov017 @ 0x021B8468; symbol: func_ov017_021b8468; size: 0x8.
extern "C" unsigned OV017_ReadWordField6AC(void* self)
{
    return *(unsigned*)((char*)self + 0x6AC);
}
