#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov017 @ 0x021D612C; symbol: func_ov017_021d612c; size: 0x8.
extern "C" unsigned OV017_ReadWordField04(void* self)
{
    return *(unsigned*)((char*)self + 4);
}
