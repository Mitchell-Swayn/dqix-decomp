// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x020A298C; symbol: func_020a298c; size: 0x10.
extern "C" void Object_ClearElement581Mask4(unsigned char* p){p[0x245]&=~4;}
