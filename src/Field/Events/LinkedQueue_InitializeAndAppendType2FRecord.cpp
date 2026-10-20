#include <globaldefs.h>
ARM
extern "C" ARM void ProfileScreen_InitializeFieldSession(unsigned char *record);
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char *p, char *entry);
// Original: arm9/ov017 @ 0x021C1798; symbol: func_ov017_021c1798; size: 0x34.
extern "C" void LinkedQueue_InitializeAndAppendType2FRecord(unsigned char *p, unsigned char value) {
    ProfileScreen_InitializeFieldSession(*(unsigned char **)(p + 0x3B54));
    *(unsigned char *)(*(unsigned char **)(p + 0x3B54) + 0x1D) = value;
    LinkedQueue_InsertAfterHeadAndMarkLinked(*(char **)(p + 0x36FC), (char *)*(unsigned char **)(p + 0x3B54));
}
