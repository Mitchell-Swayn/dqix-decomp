struct Target { unsigned char unknown[0x56e]; unsigned char flag; };
struct Owner { unsigned char unknown[0x150]; Target* target; };
// Original: arm9/ov005 @ 0x021583FC; symbol: func_ov005_021583fc; size: 0x10.
extern "C" void FieldAppearance_SetMemberRefreshRequest(Owner* self, unsigned char flag) { if (self->target) self->target->flag = flag; }
