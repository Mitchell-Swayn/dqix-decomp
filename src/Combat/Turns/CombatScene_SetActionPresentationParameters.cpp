// Original: arm9/ov000 @ 0x02163440; symbol: func_ov000_02163440; size: 0x14.
extern "C" void CombatScene_SetActionPresentationParameters(unsigned char *record, unsigned short a, unsigned short b, unsigned short c) { unsigned char *p = record + 0x6e00; *(unsigned short *)(p + 0x44) = a; *(unsigned short *)(p + 0x46) = b; *(unsigned short *)(p + 0x48) = c; }
