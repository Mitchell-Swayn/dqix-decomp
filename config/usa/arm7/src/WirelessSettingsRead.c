/* Copy settings bytes through the wireless-memory byte accessors. Offsets use
 * the original settings header origin0x2a; a missing table leaves output alone. */
#pragma dont_inline on
typedef struct { unsigned char unknown000[0x318]; const unsigned char *settings; } WirelessSettingsView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessSettingsView *ARM7_WirelessSettingsState;
extern unsigned char ARM7_ReadWirelessMemoryByte(const unsigned char *source);
extern void ARM7_WriteWirelessMemoryByte(unsigned char *destination, unsigned int value);
// Original: arm7/mainram @ 0x027F5128; symbol: func_027f5128; size: 0x60.
void ARM7_ReadWirelessSettingsBytes(unsigned int offset, unsigned int size, void *destination)
{
    const unsigned char *settings = ARM7_WirelessSettingsState->settings;
    const unsigned char *source;
    unsigned char *output = (unsigned char *)destination;
    if (settings) {
        source = settings + offset - 0x2a;
        while (size) {
            ARM7_WriteWirelessMemoryByte(output, ARM7_ReadWirelessMemoryByte(source++));
            output++;
            size--;
        }
    }
}
