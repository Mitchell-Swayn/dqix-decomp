// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x020A2CC4; symbol: func_020a2cc4; size: 0x14.
extern "C" int Camera_IsRecentering(unsigned char* p){return (p[0x245]&2)!=0;}
