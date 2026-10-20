#include <globaldefs.h>
ARM
extern "C" int GameState_ReadProtagonistObjectIndex(void *);
extern "C" unsigned char *LinkedQueue_GetFrontNode(void *);
extern "C" void FieldTransition_InitializeRequestDefaults(char *);
extern "C" void GameState_ResetTransitionFlagsToEnabled(char *);
extern "C" void GameState_ReplacePendingFieldTransition(void *, void *);
// Original: arm9/ov017 @ 0x021CF5D4; symbol: func_ov017_021cf5d4; size: 0x7C.
extern "C" void Field_ApplyTargetedZoneTransition(char *object, char *entry, void *gameState, char *resources) {
    if (*(signed char *)(entry + 6) == GameState_ReadProtagonistObjectIndex(gameState)) {
        if (LinkedQueue_GetFrontNode((void *)*(unsigned int *)((char *)resources + 0x36fc)) == 0) {
            char record[0x70];
            FieldTransition_InitializeRequestDefaults(record);
            *(unsigned short *)record = *(unsigned short *)(entry + 4);
            record[2] = 1;
            if (*(unsigned char *)(entry + 7) != 0)
                GameState_ResetTransitionFlagsToEnabled((char *)gameState);
            GameState_ReplacePendingFieldTransition(gameState, record);
        }
    }
}
