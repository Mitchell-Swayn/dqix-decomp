#include <globaldefs.h>
ARM
extern "C" void *FindReadyRecordByIdBeforeStopIndex(void *owner, unsigned id);
extern "C" void WriteFieldD8Bit0AndResetProgress(unsigned char *self, unsigned value);
// Original: arm9/ov000 @ 0x0217A9D0; symbol: func_ov000_0217a9d0; size: 0x38.
extern "C" void GameState_UpdateReadyRecordProgress(int id, int stopIndex, int progress, void *owner) {
    unsigned char *record = (unsigned char *)FindReadyRecordByIdBeforeStopIndex(owner, (unsigned)id);
    if (!record) return;
    unsigned value = 0;
    if (progress < stopIndex) value = 1;
    WriteFieldD8Bit0AndResetProgress(record, value);
}
