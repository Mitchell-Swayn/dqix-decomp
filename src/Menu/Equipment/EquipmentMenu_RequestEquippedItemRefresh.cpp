extern "C" void GameState_CopySelectedSubrecordValues(void*);
struct State { unsigned char unknown[0xda9]; unsigned char state; unsigned char unknown2[0x22]; unsigned flags; };
struct Owner { unsigned char unknown[0x3000]; State state; };
// Original: arm9/ov005 @ 0x021551D4; symbol: func_ov005_021551d4; size: 0x28.
extern "C" void EquipmentMenu_RequestEquippedItemRefresh(Owner* self) {GameState_CopySelectedSubrecordValues(self); self->state.flags |= 0x20; self->state.state=0;}
