#include <globaldefs.h>
// Layout recovered from this overlay's field-access instruction offsets.
struct Node { unsigned kind; unsigned payload; };
struct State {
 unsigned kind; Node* child; char pad08[0x94]; unsigned f9c;
 char pada0[0x10]; unsigned fb0, fb4; char padb8[0x54]; unsigned f10c;
 char pad110[4]; unsigned f114; char pad118[0x74]; unsigned f18c;
 char pad190[0x20]; unsigned short f1b0, f1b2; unsigned f1b4, f1b8;
 char pad1bc[4]; unsigned short f1c0,f1c2,f1c4,f1c6; unsigned f1c8;
 char pad1cc[8]; unsigned f1d4,f1d8,f1dc;
};
extern "C" unsigned GetMainBGVRAMBanks(void);
extern "C" unsigned GetSubBGVRAMBanks(void);
// Original: arm9/ov011 @ 0x02184A18; symbol: func_ov011_02184a18; size: 0xC.
extern "C" unsigned func_ov011_02184a18(State* self) { return self->f1b2; }
