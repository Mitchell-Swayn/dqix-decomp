#include <globaldefs.h>
ARM
extern "C" int data_ov002_0216c9dc[];
// Original: arm9/ov002 @ 0x0215A9F0; symbol: func_ov002_0215a9f0; size: 0x24.
extern "C" int GameState_ReadIndexedSignedByte(void *object) {
    int index = *(short *)((char *)object + 0x1c0a);
    int offset = data_ov002_0216c9dc[index];
    return *(signed char *)((char *)object + offset + 0x1c7c);
}
