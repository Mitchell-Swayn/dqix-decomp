#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt02108844(void);
extern "C" void GameState_ApplyEncodedFlagUpdate(void *, int, unsigned, int, int);
extern "C" void ResourceContext_SetActiveFlagIfIdle(void *);
// Original: arm9/ov017 @ 0x021D097C; symbol: func_ov017_021d097c; size: 0x48.
extern "C" void ApplyFlagRecordAndMaybeActivate(void *unused0, unsigned char *record, void *unused2, void *context) {
    GameState_ApplyEncodedFlagUpdate(ReadGlobalValueAt02108844(), record[4], record[5], *(unsigned short *)(record + 6), *(unsigned short *)(record + 8));
    unsigned char kind = record[4];
    if (kind == 0 || kind == 2 || kind == 7)
        ResourceContext_SetActiveFlagIfIdle(context);
}
