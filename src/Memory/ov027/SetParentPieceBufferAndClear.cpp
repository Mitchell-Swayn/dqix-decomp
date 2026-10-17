#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov027_021e3424[];
extern "C" void VectorizedMemset(void *destination, int value, unsigned int size);
// Original: arm9/ov027 @ 0x021DD5D4; symbol: func_ov027_021dd5d4; size: 0x20.
extern "C" void SetParentPieceBufferAndClear(void *buffer) {
    *(void **)(data_ov027_021e3424 + 4) = buffer;
    VectorizedMemset(buffer, 0, 0x21c);
}
