#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0215FC60; symbol: func_ov000_0215fc60; size: 0x2C.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM int ClassifyField81FE(unsigned char* p) {
 unsigned int value=*(unsigned short*)(p+0x81fe);
 if(value==800) return 1; if(value==801) return 2; return 0;
}
