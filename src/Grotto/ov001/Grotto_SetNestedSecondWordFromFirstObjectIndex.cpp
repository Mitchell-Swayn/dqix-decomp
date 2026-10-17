#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_ReadFirstObjectIndex(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x02161D08; symbol: func_ov001_02161d08; size: 0x24.
extern "C" int Grotto_SetNestedSecondWordFromFirstObjectIndex(void* p) { void* state = _ZN9GameState11GetInstanceEv(); int index = GameState_ReadFirstObjectIndex(state); SetNestedSecondWordForTypeThree(p, index); return 1; }
