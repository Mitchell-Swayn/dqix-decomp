// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x020415C4; symbol: func_020415c4; size: 0x14.
extern "C" unsigned int Object3D_ReadFlagSelectedPlaybackWord(char* p){if(*(unsigned short*)(p+0xac)&2)return *(unsigned int*)(p+0xb0);return *(unsigned int*)(p+0x54);}
