#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0207C694; symbol: func_0207c694; size: 0x14.
unsigned int Inventory_GetGroupSaveMetadata(unsigned char *p,unsigned int i){if(i>7)return 255;return *(p+i+0xc28);}
}
