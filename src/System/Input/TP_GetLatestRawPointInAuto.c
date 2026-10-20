// Original: arm9/main @ 0x020CDC7C; symbol: func_020cdc7c; size: 0x144.
#include <globaldefs.h>
// Keep the small TPData copies expanded, as in the original SDK build.
#pragma optimize_for_size off
typedef struct TPData { unsigned short x, y, touch, validity; } TPData;
typedef struct TPWork { char prefix[0x10]; unsigned short latestIndex, sampleCount; TPData *buffer; unsigned short bufferSize; } TPWork;
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern TPWork TPWaitBusy_UnknownRoleZeroInitializedStorage;
// ARM9 main, original func_020cdc7c at 0x020cdc7c; SDK TP_GetLatestRawPointInAuto.
// TPData layout and algorithm identified from pinned pret/pokediamond SPI_tp.s and tp.h.
ARM void TP_GetLatestRawPointInAuto(TPData *result)
{
    int i;
    unsigned latest;
    result->validity = 3;
    latest = TPWaitBusy_UnknownRoleZeroInitializedStorage.latestIndex;
    if (TPWaitBusy_UnknownRoleZeroInitializedStorage.sampleCount == 1 || TPWaitBusy_UnknownRoleZeroInitializedStorage.bufferSize == 1) {
        *result = TPWaitBusy_UnknownRoleZeroInitializedStorage.buffer[latest];
        return;
    }
    for (i = 0; i < TPWaitBusy_UnknownRoleZeroInitializedStorage.sampleCount && i < TPWaitBusy_UnknownRoleZeroInitializedStorage.bufferSize - 1; i++) {
        int index;
        TPData *sample;
        index = latest - i;
        if (index < 0) index += TPWaitBusy_UnknownRoleZeroInitializedStorage.bufferSize;
        sample = &TPWaitBusy_UnknownRoleZeroInitializedStorage.buffer[index];
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
