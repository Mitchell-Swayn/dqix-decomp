struct ContextFlagView14 { unsigned char pad[0x14]; unsigned int flags; };
struct ContextFlagOwner14 { unsigned char pad[0x138]; ContextFlagView14* view; };
// Original: arm9/ov024 @ 0x021edbc0; symbol: func_ov024_021edbc0; size: 0x18
extern "C" int Combatant_TestPrimaryStatusFlagBit27(ContextFlagOwner14* owner)
{
    return (owner->view->flags & 0x08000000) != 0;
}
