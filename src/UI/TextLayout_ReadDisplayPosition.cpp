#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02066CC0; symbol: func_02066cc0; size: 0x20.
extern "C" void TextLayout_ReadDisplayPosition(unsigned char* p,short* x,short* y) { if (*(short**)(p+0x440)) { *x=**(short**)(p+0x440); *y=(*(short**)(p+0x440))[1]; } }
