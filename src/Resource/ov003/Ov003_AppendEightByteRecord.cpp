#include <globaldefs.h>
// Original: arm9/ov003 @ 0x0215E898; symbol: func_ov003_0215e898; size: 0x5C.
extern "C" void Ov003_AppendEightByteRecord(char *container, char *source) {
    char *records = *(char **)(container + 8);
    if (records == 0) return;
    short index = *(short *)(container + 0x0e);
    if (*(short *)(container + 0x0c) <= index) return;
    char *destination = records + index * 8;
    *(unsigned char *)destination = *(unsigned char *)source;
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
    *(unsigned int *)(destination + 4) = *(unsigned int *)(source + 4);
    ++*(short *)(container + 0x0e);
}
