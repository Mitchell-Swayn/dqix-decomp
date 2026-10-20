#include <globaldefs.h>
ARM
extern "C" void *GameState_GetSerializedProgressState(void);
extern "C" void GameState_ApplyEncodedFlagUpdate(void *, int, unsigned, int, int);
extern "C" void Field_MarkClientZoneRefreshPending(void *);
// Original: arm9/ov017 @ 0x021D097C; symbol: func_ov017_021d097c; size: 0x48.
extern "C" void FieldNetwork_ApplyProgressFlagUpdateAndReactivate(void *unused0, unsigned char *record, void *unused2, void *context) {
    GameState_ApplyEncodedFlagUpdate(GameState_GetSerializedProgressState(), record[4], record[5], *(unsigned short *)(record + 6), *(unsigned short *)(record + 8));
    unsigned char kind = record[4];
    if (kind == 0 || kind == 2 || kind == 7)
        Field_MarkClientZoneRefreshPending(context);
}
