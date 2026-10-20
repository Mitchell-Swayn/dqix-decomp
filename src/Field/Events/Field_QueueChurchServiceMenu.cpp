#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void Field_InitializeChurchServiceCommand(void *record);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int *p, unsigned int n);
// Original: arm9/ov017 @ 0x021BA8E0; symbol: func_ov017_021ba8e0; size: 0x2C.
extern "C" void Field_QueueChurchServiceMenu(void *state) {
    TextContext_GetSharedInstance();
    Field_InitializeChurchServiceCommand(*(void **)((char *)state + 0x372c));
    LinkedQueue_AppendAndMarkActive(*(unsigned int **)((char *)state + 0x36fc), *(unsigned int *)((char *)state + 0x372c));
}
