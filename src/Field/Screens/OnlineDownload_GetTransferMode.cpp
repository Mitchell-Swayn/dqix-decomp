// Returns byte 0x34 from the pointer at record offset 0x24, or zero when that pointer is null.
extern "C" {
// Original: arm9/ov017 @ 0x021B2024; symbol: func_ov017_021b2024; size: 0x14.
unsigned int OnlineDownload_GetTransferMode(const unsigned char* record)
{
    const unsigned char* nested = *(const unsigned char**)(record + 0x24);
    return nested != 0 ? nested[0x34] : 0;
}
}
