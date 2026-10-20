struct ContextFlagView30 { unsigned char pad[0x14]; unsigned int flags; };
struct ContextFlagOwner30 { unsigned char pad[0x138]; ContextFlagView30* view; };
// Original: arm9/ov024 @ 0x021edc50; symbol: func_ov024_021edc50; size: 0x18
extern "C" int Combatant_TestPrimaryStatusFlagBit30(ContextFlagOwner30* owner)
{
    return (owner->view->flags & 0x40000000) != 0;
}
