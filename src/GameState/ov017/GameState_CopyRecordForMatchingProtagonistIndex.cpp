#include <globaldefs.h>
ARM
extern "C" int GameState_ReadProtagonistObjectIndex(void *);
extern "C" unsigned char *Record_ReadInitialWord(void *);
extern "C" void InitializeRecordWithEnabledAndInvalidIndices(char *);
extern "C" void Object_ResetByte63DCToBit0(char *);
extern "C" void GameState_CopyChunkAtOffset3F8(void *, void *);
// Original: arm9/ov017 @ 0x021CF5D4; symbol: func_ov017_021cf5d4; size: 0x7C.
extern "C" void GameState_CopyRecordForMatchingProtagonistIndex(char *object, char *entry, void *gameState, char *resources) {
    if (*(signed char *)(entry + 6) == GameState_ReadProtagonistObjectIndex(gameState)) {
        if (Record_ReadInitialWord((void *)*(unsigned int *)((char *)resources + 0x36fc)) == 0) {
            char record[0x70];
            InitializeRecordWithEnabledAndInvalidIndices(record);
            *(unsigned short *)record = *(unsigned short *)(entry + 4);
            record[2] = 1;
            if (*(unsigned char *)(entry + 7) != 0)
                Object_ResetByte63DCToBit0((char *)gameState);
            GameState_CopyChunkAtOffset3F8(gameState, record);
        }
    }
}
