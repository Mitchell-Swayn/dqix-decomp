#include <globaldefs.h>
ARM
extern "C" void *Queue_AppendNodeFromFreeList(int);
// Original: arm9/ov001 @ 0x0215911C; symbol: func_ov001_0215911c; size: 0x20.
extern "C" void Util_SetFieldsIfObjectPresent(int a0, int a1) {
    char *object = (char *)Queue_AppendNodeFromFreeList(a0);
    if (object) {
        *(int *)object = 0xc;
        *(int *)(object + 0x1c) = a1;
    }
}
