// Original: arm9/ov000 @ 0x0215fa70; symbol: func_ov000_0215fa70; size: 0x14.
extern "C" void SetThreeCombatantHalfwordFields(unsigned char *record, unsigned short a, unsigned short b, unsigned short c) { unsigned char *p = record + 0x8e00; *(unsigned short *)(p + 0x4a) = a; *(unsigned short *)(p + 0x4c) = b; *(unsigned short *)(p + 0x4e) = c; }
