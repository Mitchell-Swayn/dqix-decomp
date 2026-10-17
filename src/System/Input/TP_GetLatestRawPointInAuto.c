// Original: arm9/main @ 0x020CDC7C; symbol: func_020cdc7c; size: 0x144.
#include <globaldefs.h>
// Keep the small TPData copies expanded, as in the original SDK build.
#pragma optimize_for_size off
typedef struct TPData { unsigned short x, y, touch, validity; } TPData;
typedef struct TPWork { char prefix[0x10]; unsigned short latestIndex, sampleCount; TPData *buffer; unsigned short bufferSize; } TPWork;
extern TPWork data_021117b0;
// ARM9 main, original func_020cdc7c at 0x020cdc7c; SDK TP_GetLatestRawPointInAuto.
// TPData layout and algorithm identified from pinned pret/pokediamond SPI_tp.s and tp.h.
ARM void TP_GetLatestRawPointInAuto(TPData *result)
{
    int i;
    unsigned latest;
    result->validity = 3;
    latest = data_021117b0.latestIndex;
    if (data_021117b0.sampleCount == 1 || data_021117b0.bufferSize == 1) {
        *result = data_021117b0.buffer[latest];
        return;
    }
    for (i = 0; i < data_021117b0.sampleCount && i < data_021117b0.bufferSize - 1; i++) {
        int index;
        TPData *sample;
        index = latest - i;
        if (index < 0) index += data_021117b0.bufferSize;
        sample = &data_021117b0.buffer[index];
        if (!sample->touch) { *result = *sample; return; }
        if ((result->validity & 1) && !(sample->validity & 1)) {
            result->x = sample->x;
            if (i != 0) result->validity &= ~1;
        }
        if ((result->validity & 2) && !(sample->validity & 2)) {
            result->y = sample->y;
            if (i != 0) result->validity &= ~2;
        }
        if (!result->validity) { result->touch = 1; return; }
    }
    result->touch = 1;
}
