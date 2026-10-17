#include <globaldefs.h>
ARM

extern "C" unsigned int ReadSharedFirstByte(void);
extern "C" char data_ov031_02250bb0[];
extern "C" unsigned char data_ov031_02248990[];
extern "C" char *strncpy(char *, const char *, unsigned int);

// Original: arm9/ov031 @ 0x02223478; symbol: func_ov031_02223478; size: 0x60.
extern "C" char *Unclassified_CopyStringAndNormalizeMarker(const char *source) {
    strncpy(data_ov031_02250bb0, source, 0x3f);
    if ((unsigned char)source[5] == 0x78) {
        return data_ov031_02250bb0;
    }
    unsigned int shared = ReadSharedFirstByte();
    if ((unsigned char)source[5] == 0x79 && shared != 0) {
        return data_ov031_02250bb0;
    }
    data_ov031_02250bb0[5] = data_ov031_02248990[shared];
    return data_ov031_02250bb0;
}
