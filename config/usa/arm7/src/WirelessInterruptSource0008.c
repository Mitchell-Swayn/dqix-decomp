/* Acknowledge source 8, update its hardware flag, and inspect three live frames. */
#pragma dont_inline on
typedef struct { unsigned short low:4, bit4:1, high:11; } WirelessSource8Flags;
typedef struct {
    unsigned short unknown000[2], pending, unknown006[2], length, flags;
} WirelessSource8Frame;
typedef struct {
    unsigned short active, unknown002; unsigned int unknown004;
    WirelessSource8Frame *frame; unsigned int unknown00C[2];
} WirelessSource8Record;
typedef struct { unsigned char unknown000[0xba]; unsigned short clearedFrames; } WirelessSource8Working;
typedef struct {
    unsigned char unknown000[0x33a]; WirelessSource8Flags flags;
    unsigned char unknown33C[8];
    WirelessSource8Working working;
    unsigned char unknown400[0x2c]; WirelessSource8Record records[3];
    unsigned char unknown468[0x228]; unsigned short enabled;
} WirelessSource8View;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessSource8State (*(WirelessSource8View **)0x0380fff4)
// Original: arm7/wram @ 0x037F97B0; symbol: func_037f97b0; size: 0x110.
void ARM7_HandleWirelessSource0008(void)
{
    volatile unsigned short *registers = (volatile unsigned short *)0x04808010;
    WirelessSource8View *state;
    unsigned int index;
    WirelessSource8Record *records;
    WirelessSource8Working *working;
    *registers = 8;
    if (ARM7_WirelessSource8State->flags.bit4 && !(*(volatile unsigned short *)0x0480819c & 1))
        *(volatile unsigned short *)0x04808290 ^= 1;
    state = ARM7_WirelessSource8State;
    if (!(state->enabled & 8)) return;
    working = &state->working;
    records = state->records;
    index = 0;
    do {
        WirelessSource8Record *record = &records[index];
        if (record->active) {
            WirelessSource8Frame *frame = record->frame;
            if ((frame->flags & 0x4000) && (frame->pending & 255)) {
                /* ARM7 uses 32-bit addresses; align the driver-owned frame
                 * trailer down to a halfword without arithmetic on header size. */
                unsigned int payloadAddress = (unsigned int)frame + 12;
                unsigned short *trailer = (unsigned short *)((payloadAddress + frame->length - 7) & ~1U);
                if (!trailer[0] && !trailer[1]) {
                    frame->pending = 0;
                    *(volatile unsigned short *)0x04808032 = 0;
                    *(volatile unsigned short *)0x04808032 = 0x8000;
                    working->clearedFrames++;
                }
            }
        }
        index++;
    } while (index < 3);
}
