struct ContextFlagView31 { unsigned char pad[0x14]; unsigned int flags; };
struct ContextFlagOwner31 { unsigned char pad[0x138]; ContextFlagView31* view; };
// Original: arm9/ov024 @ 0x021edc68; symbol: func_ov024_021edc68; size: 0x18
extern "C" int ReadContextFlags14Bit31(ContextFlagOwner31* owner)
{
    return (owner->view->flags & 0x80000000) != 0;
}
