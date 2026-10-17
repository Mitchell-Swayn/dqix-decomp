#include <globaldefs.h>
ARM
extern "C" void func_0205ac40(void *, void *);
// Original: arm9/ov003 @ 0x0217585C; symbol: func_ov003_0217585c; size: 0x3C.
extern "C" void Graphics_SetIndexedRecordCoordinatesAndSubmit(void *owner, int x, int y, unsigned int index, unsigned char flag) {
    unsigned char *record = *(unsigned char **)((char *)owner + 0x830) + index * 0x28;
    void *context = (char *)owner + 0x7d8;
    record[0x22] = flag;
    *(unsigned int *)(record + 0x14) = x << 12;
    *(unsigned int *)(record + 0x18) = y << 12;
    func_0205ac40(context, record);
}
