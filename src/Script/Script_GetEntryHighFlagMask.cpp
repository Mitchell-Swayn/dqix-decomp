#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0206E2DC; symbol: func_0206e2dc; size: 0x40.
unsigned int Script_GetEntryHighFlagMask(unsigned char *p,int i){if(i>=204||i<0)return 0;unsigned int mask=i%2?128:8;return *((p+i/2)+0x2cc)&mask;}
}
