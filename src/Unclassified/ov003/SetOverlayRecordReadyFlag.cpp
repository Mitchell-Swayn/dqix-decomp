// Sets byte 0x3f4 of the supplied record to one.
extern "C" {
// Original: arm9/ov003 @ 0x0215CAA4; symbol: func_ov003_0215caa4; size: 0xC.
void SetOverlayRecordReadyFlag(unsigned char* record)
{
    record[0x3F4] = 1;
}
}
