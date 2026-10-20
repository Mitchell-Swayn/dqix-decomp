#pragma thumb off
#pragma force_active on
// Original: arm9/ov000 @ 0x0217F5DC; symbol: ReadByteAtOffset445; size: 0x8.
extern "C" unsigned char BattleMenu_IsPartyPanelEnabled(const void* object)
{
    return ((const unsigned char*)object)[0x445];
}
