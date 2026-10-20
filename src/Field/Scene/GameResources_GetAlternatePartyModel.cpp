#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov017 @ 0x021BDBCC; symbol: func_ov017_021bdbcc; size: 0xC.
extern "C" unsigned GameResources_GetAlternatePartyModel(void* self)
{
    return *(unsigned*)((char*)self + 0x4338);
}
