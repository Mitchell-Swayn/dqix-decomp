#include <globaldefs.h>
extern "C" unsigned char data_ov027_021e33e0[];
// Original: arm9/ov027 @ 0x021dd038; symbol: func_ov027_021dd038; size: 0x14.
extern "C" unsigned ReadNestedGlobalHalfwordAtOffset12() {
    unsigned char* first = *(unsigned char**)(data_ov027_021e33e0 + 8);
    return *(unsigned short*)(first + 0xC);
}
