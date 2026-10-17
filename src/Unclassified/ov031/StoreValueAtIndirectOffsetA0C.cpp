#pragma thumb off
extern "C" unsigned char* data_ov031_0224e588;
// Stores a word at offset 0xA0C through the pointer held in the overlay global.
// Original: arm9/ov031 @ 0x02210314; symbol: func_ov031_02210314; size: 0x18.
extern "C" void StoreValueAtIndirectOffsetA0C(unsigned int value)
{
    if (data_ov031_0224e588 != 0)
        *(unsigned int*)(data_ov031_0224e588 + 0xA0C) = value;
}
