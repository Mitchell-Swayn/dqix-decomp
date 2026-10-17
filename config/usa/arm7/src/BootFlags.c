/* The shared boot byte's wider meaning is not established yet. This routine
 * maps its two recognized values to separate flag bits; callers consume them
 * while selecting and validating firmware settings. */
// Original: arm7/wram @ 0x037F84B8; symbol: ARM7_GetBootByteFlags.
unsigned short ARM7_GetBootByteFlags(void) {
    unsigned short flags = 0;
    unsigned char value = *(volatile unsigned char *)0x027ffe1d;

    if (value == 0x80) {
        flags |= 0x40;
    } else if (value == 0x40) {
        flags |= 0x80;
    }
    return flags;
}
