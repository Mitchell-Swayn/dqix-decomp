#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void InitializeType16Record(void *record);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *p, unsigned int n);
// Original: arm9/ov017 @ 0x021BA8E0; symbol: func_ov017_021ba8e0; size: 0x2C.
extern "C" void GameState_InitializeAndAppendType16Record(void *state) {
    ReadWordFieldAtOffset1C();
    InitializeType16Record(*(void **)((char *)state + 0x372c));
    AppendLinkedNodeAndMarkActive(*(unsigned int **)((char *)state + 0x36fc), *(unsigned int *)((char *)state + 0x372c));
}
