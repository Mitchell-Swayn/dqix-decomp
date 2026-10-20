#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_GetProgressChapter(void*);
extern "C" int GameState_ReadUnknown5cb4(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021E9208; symbol: func_ov023_021e9208; size: 0x3C.
extern "C" int GameState_WriteStateWordsToNestedParameters(void* p) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    Script_WriteIntegerReferenceOutput(p, GameState_GetProgressChapter(gameState));
    Script_WriteIntegerReferenceOutput((char*)p + 8, GameState_ReadUnknown5cb4(gameState));
    return 1;
}
