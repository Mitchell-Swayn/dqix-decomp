#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208824C; symbol: func_0208824c; size: 0x20.
extern "C" bool Object_TestFlags1And1000000Clear(unsigned int* p) { unsigned int flags=p[5]; if (flags&1) return false; return (flags&0x1000000)==0; }
