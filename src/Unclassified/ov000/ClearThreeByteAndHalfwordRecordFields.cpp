// Original: arm9/ov000 @ 0x021820fc; symbol: func_ov000_021820fc; size: 0x18.
extern "C" void ClearThreeByteAndHalfwordRecordFields(unsigned char *record) { record[0] = 0; record[1] = 0; *(unsigned short *)(record + 2) = 0; *(unsigned short *)(record + 4) = 0; }
