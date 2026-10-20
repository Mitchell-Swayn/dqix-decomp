/* Derive the hardware timing halfword from settings bytes, mode, and a
 * hardware-control bit. The initialized default also covers a missing table. */
#pragma dont_inline on
extern void ARM7_ReadWirelessSettingsBytes(unsigned int offset, unsigned int size, void *destination);
extern unsigned int ARM7_GetWirelessModeTimingValue(void);
// Original: arm7/mainram @ 0x027E9EE4; symbol: ARM7_RefreshWirelessRegister8140; size: 0x80.
void ARM7_RefreshWirelessRegister8140(void)
{
    unsigned int value = 0xe2e2;
    ARM7_ReadWirelessSettingsBytes(0x58, 2, &value);
    value += 0x202;
    if (ARM7_GetWirelessModeTimingValue() == 20) {
        value -= 0x6161;
        if (*(volatile unsigned short *)0x048080bc & 2) value -= 0x6060;
    }
    *(volatile unsigned short *)0x04808140 = value;
}
