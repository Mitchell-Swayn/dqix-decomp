#include <globaldefs.h>
ARM
extern "C" unsigned ReadSharedFirstByte(void);
extern "C" unsigned int data_ov031_02248958[];

// Original: arm9/ov031 @ 0x022236D0; symbol: func_ov031_022236d0; size: 0x18.
extern "C" unsigned int func_ov031_022236d0(void) {
    return data_ov031_02248958[ReadSharedFirstByte()];
}
