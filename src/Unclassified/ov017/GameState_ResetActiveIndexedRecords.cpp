#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" int ReadIndexedSignedField1038(char *object);
extern "C" void *GameResources_GetInstance(void);
extern "C" void ResetMatchingIndexedRecordOrAllFourRecords(void *records, int index);
extern "C" void WriteMatchingSlotFlagMask(char *self, int enabled, unsigned char mask, int wanted);
// Original: arm9/ov017 @ 0x021C6034; symbol: func_ov017_021c6034; size: 0x70.
extern "C" void GameState_ResetActiveIndexedRecords(const signed char *flags) {
    void *connection = Object_GetGlobalConnectionState();
    int activeIndex = ReadIndexedSignedField1038((char *)connection);
    if (flags[activeIndex] == 1) return;
    char *resources = (char *)GameResources_GetInstance() + 0x3000;
    char *records = *(char **)(resources + 0x6d0);
    for (int i = 0; i < 4; ++i) {
        if (flags[i] == 1) {
            ResetMatchingIndexedRecordOrAllFourRecords(records, i);
            WriteMatchingSlotFlagMask(records, 1, 1, i);
        }
    }
}
