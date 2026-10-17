#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov000 @ 0x02163524; symbol: func_ov000_02163524; size: 0x8.
extern "C" unsigned OV000_ReadWordFieldEA4(void* self)
{
    return *(unsigned*)((char*)self + 0xEA4);
}
