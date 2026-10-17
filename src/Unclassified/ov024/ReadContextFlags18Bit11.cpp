struct ContextFlagView18 { unsigned char pad[0x18]; unsigned int flags; };
struct ContextFlagOwner18 { unsigned char pad[0x138]; ContextFlagView18* view; };
// Original: arm9/ov024 @ 0x021e7ba8; symbol: func_ov024_021e7ba8; size: 0x18
extern "C" int ReadContextFlags18Bit11(ContextFlagOwner18* owner)
{
    return (owner->view->flags & 0x800) != 0;
}
