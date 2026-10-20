/* Serialize a nonvolatile-settings read using the driver's SPI service cookie. */
#pragma dont_inline on
typedef struct { unsigned char unknown000[0x314]; unsigned int spiCookie; } WirelessNvSettingsView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessNvSettingsView *ARM7_WirelessNvSettingsState;
extern void ARM7_AcquireSpiServiceToken(unsigned int cookie);
extern void ARM7_ReleaseSpiServiceToken(unsigned int cookie);
extern void ARM7_WaitWirelessNvStatusReady(void);
extern void ARM7_ReadWirelessNvByteRange(unsigned int offset, unsigned int size, void *destination);
// Original: arm7/mainram @ 0x027F5188; symbol: func_027f5188; size: 0x50.
void ARM7_ReadWirelessNvSettingsBytes(unsigned int offset, unsigned int size, void *destination)
{
    ARM7_AcquireSpiServiceToken(ARM7_WirelessNvSettingsState->spiCookie);
    ARM7_WaitWirelessNvStatusReady();
    ARM7_ReadWirelessNvByteRange(offset, size, destination);
    ARM7_ReleaseSpiServiceToken(ARM7_WirelessNvSettingsState->spiCookie);
}
