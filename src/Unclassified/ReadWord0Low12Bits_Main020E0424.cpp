// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x020E0424; symbol: func_020e0424; size: 0x10.
extern "C" unsigned int ReadWord0Low12Bits_Main020E0424(Flags* p){return p->value;}
