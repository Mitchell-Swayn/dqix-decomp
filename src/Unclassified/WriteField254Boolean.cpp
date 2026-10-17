// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x0203983C; symbol: func_0203983c; size: 0x14.
extern "C" void WriteField254Boolean(char* p,int v){p[0x254]=v!=0;}
