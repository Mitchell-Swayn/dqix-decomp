#include <globaldefs.h>
ARM
extern "C" void FieldPartyEffect_InitializeTransitionCommand(void *);
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char *, char *);
// Original: arm9/ov017 @ 0x021ACD30; symbol: func_ov017_021acd30; size: 0x4C.
extern "C" void FieldPartyEffect_QueueConfiguredTransition(void *owner, unsigned char first, unsigned char second, unsigned char third) {
    volatile unsigned char **slot = (volatile unsigned char **)((char *)owner + 0x3000 + 0xb20);
    FieldPartyEffect_InitializeTransitionCommand((void *)*slot);
    (*slot)[0x27c] = first;
    (*slot)[0x27d] = second;
    (*slot)[0x27e] = third;
    LinkedQueue_InsertAfterHeadAndMarkLinked((char *)*(unsigned int **)((char *)owner + 0x3000 + 0x6fc), (char *)*slot);
}
