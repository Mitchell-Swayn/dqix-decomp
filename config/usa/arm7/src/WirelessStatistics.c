/* Accumulate wireless hardware statistic bytes into totals. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x548];
    unsigned int counterAt548;
    unsigned int counterAt54C;
    unsigned int counterAt550;
    unsigned int counterAt554;
    unsigned int counterAt558;
    unsigned int counterAt55C;
    unsigned int counterAt560;
    unsigned int counterAt564;
    unsigned int counterAt568;
    unsigned int counterAt56C;
    unsigned int counterAt570;
    unsigned int counterAt574;
    unsigned int counterAt578;
    unsigned int counterAt57C;
    unsigned int counterAt580;
    unsigned int counterAt584;
    unsigned int counterAt588;
    unsigned int counterAt58C;
    unsigned int counterAt590;
    unsigned int counterAt594;
    unsigned int counterAt598;
    unsigned int counterAt59C;
    unsigned int counterAt5A0;
    unsigned int counterAt5A4;
    unsigned int counterAt5A8;
    unsigned int counterAt5AC;
    unsigned int counterAt5B0;
    unsigned int counterAt5B4;
    unsigned int counterAt5B8;
    unsigned int counterAt5BC;
    unsigned int counterAt5C0;
    unsigned int counterAt5C4;
    unsigned int counterAt5C8;
    unsigned int counterAt5CC;
    unsigned int counterAt5D0;
    unsigned int counterAt5D4;
    unsigned int counterAt5D8;
    unsigned int counterAt5DC;
    unsigned int counterAt5E0;
    unsigned int counterAt5E4;
    unsigned int counterAt5E8;
    unsigned int counterAt5EC;
} WirelessStatisticsView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessStatisticsState (*(WirelessStatisticsView **)0x0380fff4)
// Original: arm7/mainram @ 0x027EA4C4; symbol: func_027ea4c4; size: 0x1f8.
void ARM7_AccumulateWirelessStatistics(void)
{
    WirelessStatisticsView *state = ARM7_WirelessStatisticsState;
    volatile unsigned short *registers = (volatile unsigned short *)0x048081b0;
    int sample;
    state->counterAt58C += registers[0] & 255;
    sample = registers[1];
    state->counterAt588 += sample >> 8;
    state->counterAt598 += sample & 255;
    sample = registers[2];
    state->counterAt594 += sample >> 8;
    state->counterAt590 += sample & 255;
    sample = registers[3];
    state->counterAt59C += sample >> 8;
    state->counterAt574 += sample & 255;
    state->counterAt584 += registers[4] & 255;
    state->counterAt55C += registers[5] & 255;
    sample = registers[6];
    state->counterAt56C += sample >> 8;
    state->counterAt580 += sample & 255;
    sample = registers[7];
    state->counterAt578 += sample & 255;
    state->counterAt57C = state->counterAt57C + (sample >> 8);
    state->counterAt548 += registers[8] & 255;
    sample = registers[16];
    state->counterAt5B4 += sample >> 8;
    sample = registers[17];
    state->counterAt5B8 += sample & 255;
    state->counterAt5BC += sample >> 8;
    sample = registers[18];
    state->counterAt5C0 += sample & 255;
    state->counterAt5C4 += sample >> 8;
    sample = registers[19];
    state->counterAt5C8 += sample & 255;
    state->counterAt5CC += sample >> 8;
    sample = registers[20];
    state->counterAt5D0 += sample & 255;
    state->counterAt5D4 += sample >> 8;
    sample = registers[21];
    state->counterAt5D8 += sample & 255;
    state->counterAt5DC += sample >> 8;
    sample = registers[22];
    state->counterAt5E0 += sample & 255;
    state->counterAt5E4 += sample >> 8;
    sample = registers[23];
    state->counterAt5E8 += sample & 255;
    state->counterAt5EC += sample >> 8;
}
