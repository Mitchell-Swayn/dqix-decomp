/* Acknowledge source 0x2000 and advance its small working-state transition. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[8]; unsigned short status;
    unsigned char unknown00A[2]; unsigned short mode;
    unsigned char unknown00E[12]; unsigned short transition;
} WirelessSource2000Working;
typedef struct { unsigned char unknown000[0x344]; WirelessSource2000Working working; } WirelessSource2000View;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessSource2000State (*(WirelessSource2000View **)0x0380fff4)
// Original: arm7/wram @ 0x037F9714; symbol: func_037f9714; size: 0x6c.
void ARM7_HandleWirelessSource2000(void)
{
    volatile unsigned short *registers = (volatile unsigned short *)0x04808010;
    WirelessSource2000Working *working = &ARM7_WirelessSource2000State->working;
    registers[0] = 0x2000;
    registers[0x9c / 2] = 13;
    if (working->transition == 1) working->transition = 2;
    else if (working->transition == 2) working->transition = 0;
    else if (working->mode == 2 && working->status != 0x40) registers[0x38 / 2] = 0;
}
