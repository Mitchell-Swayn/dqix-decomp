#pragma thumb off
#pragma define_section init ".init" RX
extern float data_020f0b30[4];
extern float data_02108d48[5];
// Original: arm9/main @ 0x020E5F9C; symbol: __sinit_020e5f9c; size: 0x88.
// Initialize cumulative float boundaries from four existing spacing constants.
extern "C" __declspec(section "init") void __sinit_020e5f9c()
{
    data_02108d48[3] = data_020f0b30[0] + (data_020f0b30[1] + (data_020f0b30[3] + data_020f0b30[2]));
    float boundary = data_02108d48[2] + data_020f0b30[3];
    float spacing = data_020f0b30[2];
    data_02108d48[1] = boundary;
    boundary += spacing;
    spacing = data_020f0b30[1];
    data_02108d48[0] = boundary;
    data_02108d48[4] = boundary + spacing;
}
