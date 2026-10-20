#pragma thumb off
typedef unsigned short u16;
typedef unsigned int u32;
struct SixFieldRecord {
    u32 word0;
    u16 half4;
    u16 half6;
    u32 word8;
    u16 halfC;
    u16 halfE;
};
// Clears the six integer fields at offsets 0, 4, 6, 8, 0xC, and 0xE.
// Original: arm9/ov003 @ 0x0215E6D8; symbol: func_ov003_0215e6d8; size: 0x20.
extern "C" void TextEntry_InitializeControlAndGridTables(SixFieldRecord* record)
{
    record->word0 = 0;
    record->half4 = 0;
    record->half6 = 0;
    record->word8 = 0;
    record->halfC = 0;
    record->halfE = 0;
}
