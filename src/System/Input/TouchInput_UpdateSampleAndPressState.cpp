#include <globaldefs.h>

extern "C" int TouchInput_ResetTrackingState(void *);
extern "C" int Graphics_DecodeSignedBrightness(int);
extern "C" int abs(int);
extern "C" int BeginField96TransferAndSnapshotCoordinates(void *);
extern "C" int Input_ConfigureSamplingAndSynchronizePendingValues(void *);
extern "C" int TouchInput_UpdatePressReleaseAndMotionCounters(void *);
extern "C" int SetDirectionalFlagsFromStoredPoint(void *);
extern "C" int ReadSelectedCoordinatePair(void *, int *, int *);
extern "C" unsigned char TouchInput_UpdateRepeatCountdown(void *);
// Original: arm9/main @ 0x02012538; symbol: func_02012538; size: 0x1FC.
extern "C" bool TouchInput_UpdateSampleAndPressState(int base) {
    unsigned char *p = (unsigned char *)base;
    register unsigned int enabled = *(unsigned char *)(base + 0x61);
    if (!enabled) { TouchInput_ResetTrackingState(p); return 0; }
    int a = Graphics_DecodeSignedBrightness(0x0400106c);
    int b = Graphics_DecodeSignedBrightness(0x0400006c);
    int distance = abs(b) + abs(a);
    if (distance >= 0x20) BeginField96TransferAndSnapshotCoordinates(p);
    else if (p[0x60] != 0) Input_ConfigureSamplingAndSynchronizePendingValues(p);
    if (((*(volatile unsigned short *)0x027fffa8 & 0x8000) >> 15) != 0) return 0;
    if (*(unsigned short *)(p + 0x24) != 0) {
        p[0x55] = 0;
        *(int *)(p + 0x38) = *(unsigned short *)(p + 0x20);
        *(int *)(p + 0x3c) = *(unsigned short *)(p + 0x22);
        if (!TouchInput_UpdatePressReleaseAndMotionCounters(p)) return 0;
        p[0x5e] = p[0x5d];
        if (*(unsigned short *)(p + 0x24) == 0) { p[0x54] = 1; p[0x5d] = 0; } else p[0x5d] = 1;
        SetDirectionalFlagsFromStoredPoint(p);
        p[0x5c] = TouchInput_UpdateRepeatCountdown(p);
        return *(unsigned short *)(p + 0x24) != 0;
    }
    *(int *)(p + 0x38) = *(unsigned short *)(p + 0x20);
    *(int *)(p + 0x3c) = *(unsigned short *)(p + 0x22);
    p[0x5e] = p[0x5d]; p[0x5d] = 1; p[0x54] = 0;
    if (!TouchInput_UpdatePressReleaseAndMotionCounters(p)) return 0;
    SetDirectionalFlagsFromStoredPoint(p);
    if (*(unsigned short *)(p + 0x24) != 0) {
        p[0x55] = 1;
        if (*(int *)(p + 0x68) < 0 && *(int *)(p + 0x6c) < 0)
            ReadSelectedCoordinatePair(p, (int *)(p + 0x30), (int *)(p + 0x34));
        else { *(int *)(p + 0x30) = *(int *)(p + 0x68); *(int *)(p + 0x34) = *(int *)(p + 0x6c); }
        p[0x5d] = 1;
    } else {
        *(int *)(p + 0x38) = *(unsigned short *)(p + 0x20);
        *(int *)(p + 0x3c) = *(unsigned short *)(p + 0x22);
        p[0x5d] = 0;
    }
    if (p[0x62] == 0) { *(int *)(p + 0x6c) = -1; *(int *)(p + 0x68) = -1; }
    p[0x63] = 0;
    p[0x5c] = TouchInput_UpdateRepeatCountdown(p);
    return *(unsigned short *)(p + 0x24) != 0;
}
