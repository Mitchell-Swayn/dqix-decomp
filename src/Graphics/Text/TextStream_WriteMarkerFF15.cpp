#include <globaldefs.h>
#include <std_library_functions.h>
// Original: arm9/main @ 0x02069EFC; symbol: func_02069efc; size: 0x28.
extern "C" unsigned TextStream_WriteMarkerFF15(void** output) { unsigned short value; void* dest=*output; value=0xff15; memcpy(dest,&value,2);return 2; }
