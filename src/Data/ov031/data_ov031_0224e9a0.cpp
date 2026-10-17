// Runtime CRC-32 lookup table. func_ov031_0221e31c fills 256 word entries using reflected polynomial 0xedb88320; func_ov031_0221e2e4 indexes words by (crc ^ inputByte) & 255.
extern "C" {
unsigned int data_ov031_0224e9a0[256];
}
