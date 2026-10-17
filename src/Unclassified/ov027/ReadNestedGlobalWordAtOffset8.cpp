#include <globaldefs.h>
extern "C" unsigned char data_ov027_021e33e0[];
// Original: arm9/ov027 @ 0x021dd024; symbol: func_ov027_021dd024; size: 0x14.
extern "C" unsigned ReadNestedGlobalWordAtOffset8() {
    unsigned char* first = *(unsigned char**)(data_ov027_021e33e0 + 8);
    return *(unsigned*)(first + 8);
}
