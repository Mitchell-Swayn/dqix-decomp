#include <globaldefs.h>
ARM
extern "C" void func_ov002_02157480(void *, unsigned int *);
// Original: arm9/ov002 @ 0x021574D4; symbol: func_ov002_021574d4; size: 0x2C.
extern "C" int Data_GetIndexedDecodedWord(void *data, int index) {
    if (index < 0)
        return -1;
    unsigned int fields[4];
    func_ov002_02157480(data, fields);
    return (int)fields[index];
}
