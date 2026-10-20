// Original: arm9/ov000 @ 0x02165480; symbol: func_ov000_02165480; size: 0x10.
extern "C" void GameObject_SetBattleActionScriptIfAttached(unsigned char *record, unsigned int value) { unsigned int *p = *(unsigned int **)(record + 0x13c); if (p != 0) *p = value; }
