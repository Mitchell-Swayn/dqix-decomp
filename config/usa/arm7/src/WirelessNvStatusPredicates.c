/* Status is received as one byte. The unsigned representation view retains
 * the original halfword load; only initialized bits0 and1 are inspected on
 * the pinned little-endian ARM ABI. This is a C union representation view;
 * no portable C++ interpretation is implied. Unsigned16 has no trap values,
 * and unspecified upper-byte values never contribute to either result. */
#pragma dont_inline on
typedef union { unsigned short representation; unsigned char byte; } WirelessNvStatusHalfword;
extern void ARM7_ReadWirelessNvStatusByte(unsigned char *status);
// Original: arm7/mainram @ 0x027F5768; symbol: func_027f5768; size: 0x24.
int ARM7_IsWirelessNvReady(void)
{
    WirelessNvStatusHalfword status;
    ARM7_ReadWirelessNvStatusByte(&status.byte);
    return !(status.representation & 1);
}
// Original: arm7/mainram @ 0x027F578C; symbol: func_027f578c; size: 0x30.
int ARM7_IsWirelessNvWriteEnabledAndReady(void)
{
    WirelessNvStatusHalfword status;
    ARM7_ReadWirelessNvStatusByte(&status.byte);
    if (status.representation & 1) return 0;
    return (status.representation & 2) != 0;
}
