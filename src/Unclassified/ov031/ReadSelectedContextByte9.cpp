#include <globaldefs.h>
extern "C" unsigned char* data_ov031_02290d34;
// Original: arm9/ov031 @ 0x0223C054; symbol: func_ov031_0223c054; size: 0x24.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM unsigned int ReadSelectedContextByte9(int screen) {
 unsigned char* p; if(screen==1) p=data_ov031_02290d34; else p=data_ov031_02290d34+12; return p[9];
}
