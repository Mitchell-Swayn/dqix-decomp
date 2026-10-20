/* Store a validated interval, optionally mirror it to hardware, and update
 * the two interval bytes in a live wireless frame when one exists. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x33c];
    unsigned short interval;
    unsigned char unknown33E[0x14];
    unsigned short secondaryMode;
    unsigned char unknown354[0x86];
    unsigned short frameOffset;
    unsigned char unknown3DC[0xc8];
    unsigned short framePresent;
    unsigned char unknown4A6[6];
    unsigned char *frame;
} WirelessIntervalView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessIntervalView *ARM7_WirelessIntervalState;
extern void ARM7_WriteWirelessMemoryByte(unsigned char *destination, unsigned int value);
// Original: arm7/mainram @ 0x027E94C8; symbol: func_027e94c8; size: 0xb0.
int ARM7_SetWirelessInterval(unsigned short value, int mirrorToHardware)
{
    unsigned char *field;
    if (value < 10) return 5;
    ARM7_WirelessIntervalState->interval = value;
    if (mirrorToHardware) *(volatile unsigned short *)0x04808134 = value;
    if (ARM7_WirelessIntervalState->framePresent) {
        field = ARM7_WirelessIntervalState->frame + 0x24 + ARM7_WirelessIntervalState->frameOffset;
        if (ARM7_WirelessIntervalState->secondaryMode == 1) {
            ARM7_WriteWirelessMemoryByte(field + 6, value & 255);
            ARM7_WriteWirelessMemoryByte(field + 7, (value >> 8) & 255);
        } else {
            ARM7_WriteWirelessMemoryByte(field + 6, 255);
            ARM7_WriteWirelessMemoryByte(field + 7, 255);
        }
    }
    return 0;
}
