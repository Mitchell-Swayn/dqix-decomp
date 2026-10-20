#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void FieldCommandQueue_DrawActiveCommandWorldObjects(void *, unsigned int);
// Original: arm9/ov017 @ 0x021AFA9C; symbol: Resource_DispatchGameResourceEntryWord; size: 0x20.
// Loads the handler pointer at GameResources offset 0x3700 and dispatches the input word at +4.
extern "C" void Resource_DispatchGameResourceEntryWord(unsigned char *input) {
    unsigned char *resources = (unsigned char *)GameResources_GetInstance();
    void *entry = *(void **)(resources + 0x3700);
    FieldCommandQueue_DrawActiveCommandWorldObjects(entry, *(unsigned int *)(input + 4));
}
