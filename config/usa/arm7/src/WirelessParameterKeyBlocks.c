/* Upload four 20-byte parameter blocks, spaced by 32 bytes in wireless hardware. */
#pragma dont_inline on
extern void ARM7_CopyHalfwordsToWirelessMemory(const void *source, void *destination, int size);
// Original: arm7/mainram @ 0x027E93C0; symbol: func_027e93c0; size: 0x60.
int ARM7_UploadWirelessTwentyByteParameterBlocks(const unsigned char *source)
{
    ARM7_CopyHalfwordsToWirelessMemory(source, (void *)0x04805f80, 20);
    ARM7_CopyHalfwordsToWirelessMemory(source + 20, (void *)0x04805fa0, 20);
    ARM7_CopyHalfwordsToWirelessMemory(source + 40, (void *)0x04805fc0, 20);
    ARM7_CopyHalfwordsToWirelessMemory(source + 60, (void *)0x04805fe0, 20);
    return 0;
}
