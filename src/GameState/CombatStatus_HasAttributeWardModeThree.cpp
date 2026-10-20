struct F{unsigned short low:9;unsigned short mode:3;unsigned short high:4;};
// Original: arm9/main @ 0x02088740; symbol: func_02088740; size: 0x2C.
extern "C" int CombatStatus_HasAttributeWardModeThree(char* p){if(*(unsigned int*)(p+24)&128){if(((F*)(p+34))->mode==3)return 1;}return 0;}
