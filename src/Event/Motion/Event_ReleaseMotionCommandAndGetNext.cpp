#include <globaldefs.h>
ARM
extern "C" void Ov001_InitializeSessionRecord(void *);
// Original: arm9/ov001 @ 0x02159EF0; symbol: func_ov001_02159ef0; size: 0x24.
extern "C" unsigned int Event_ReleaseMotionCommandAndGetNext(void *unused, void *object) {
    if (!object) return 0;
    unsigned int value = *(unsigned int *)((unsigned char *)object + 0x3c);
    Ov001_InitializeSessionRecord(object);
    return value;
}
