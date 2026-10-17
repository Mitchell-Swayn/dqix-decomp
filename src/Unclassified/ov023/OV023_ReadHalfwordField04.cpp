#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov023 @ 0x021F6F10; symbol: func_ov023_021f6f10; size: 0x8.
extern "C" unsigned OV023_ReadHalfwordField04(void* self)
{
    return *(unsigned short*)((char*)self + 4);
}
