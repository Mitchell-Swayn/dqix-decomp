/* Acknowledge the wireless 0x0800 source. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027EBB48; symbol: func_027ebb48; size: 0x14.
void ARM7_HandleWirelessSource0800(void)
{
    *(volatile unsigned short *)0x04808010 = 0x800;
}
