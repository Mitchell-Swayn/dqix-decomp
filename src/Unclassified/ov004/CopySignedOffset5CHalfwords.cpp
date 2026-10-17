// Copies signed halfwords at offsets 0x5C and 0x5E into separate output slots.
// Original: arm9/ov004 @ 0x0216351C; symbol: func_ov004_0216351c; size: 0x14.
extern "C" void CopySignedOffset5CHalfwords(const unsigned char* object, short* first, short* second) {
    *first = *(const short*)(object + 0x5C);
    *second = *(const short*)(object + 0x5E);
}
