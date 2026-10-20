#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov031 @ 0x0223BAA0; symbol: func_ov031_0223baa0; size: 0xC.
extern "C" void* WfcUtility_GetSpriteGroupEntry(void* self, unsigned index)
{
    return *(char**)((char*)self + 8) + index * 8;
}
