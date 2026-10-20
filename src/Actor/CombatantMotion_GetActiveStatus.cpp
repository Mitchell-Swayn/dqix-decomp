// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original: arm9/main @ 0x02049EE8; symbol: func_02049ee8; size: 0x14.
extern "C" int CombatantMotion_GetActiveStatus(char* p) {char* q=*(char**)(p+0x13c); return q ? (unsigned char)q[0x56] : 0;}
