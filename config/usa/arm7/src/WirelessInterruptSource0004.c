/* Acknowledge source 4 and recover stalled frame/control hardware state. */
#pragma dont_inline on
typedef struct { unsigned short active; unsigned char unknown002[18]; } WirelessSource4Record;
typedef struct { unsigned short unknown000, retries; } WirelessSource4Control;
typedef struct {
    unsigned char unknown000[0x3fe]; unsigned short clearedFrames;
    unsigned char unknown400[0x2c]; WirelessSource4Record records[3];
    unsigned char unknown468[0x74]; WirelessSource4Control control;
    unsigned char unknown4E0[0x1b0]; unsigned short enabled;
} WirelessSource4View;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessSource4State (*(WirelessSource4View **)0x0380fff4)
extern void ARM7_RefreshWirelessReceiveState(void);
// Original: arm7/wram @ 0x037F98C0; symbol: func_037f98c0; size: 0x17c.
void ARM7_HandleWirelessSource0004(void)
{
    WirelessSource4View *state = ARM7_WirelessSource4State;
    WirelessSource4Control *control = &state->control;
    WirelessSource4Record *records = state->records;
    unsigned int status;
    *(volatile unsigned short *)0x04808010 = 4;
    status = *(volatile unsigned short *)0x048081a8;
    if ((ARM7_WirelessSource4State->enabled & 8) && (status & 0x400)) {
        unsigned short busy = *(volatile unsigned short *)0x048080b0;
        if (!(((busy & 1) && records[0].active) || ((busy & 4) && records[1].active) ||
            ((busy & 8) && records[2].active) || (*(volatile unsigned short *)0x0480819c & 1))) {
            *(volatile unsigned short *)0x04808032 = 0;
            *(volatile unsigned short *)0x04808032 = 0x8000;
            control->retries = 0;
        } else {
            unsigned short retries = control->retries++;
            if (retries > 12) {
                control->retries = 0;
                *(volatile unsigned short *)0x04808032 = 0;
                *(volatile unsigned short *)0x04808032 = 0x8000;
                ARM7_WirelessSource4State->clearedFrames++;
            }
        }
    }
    if ((ARM7_WirelessSource4State->enabled & 1) && (status & 0x60)) {
        int current = *(volatile unsigned short *)0x04808054;
        if (current >= ((int)*(volatile unsigned short *)0x04808052 - 0x4000) / 2 ||
            current < ((int)*(volatile unsigned short *)0x04808050 - 0x4000) / 2) {
            *(volatile unsigned short *)0x04808056 = *(volatile unsigned short *)0x0480805a;
            *(volatile unsigned short *)0x04808030 = 0x8001;
        }
        ARM7_RefreshWirelessReceiveState();
    }
}
