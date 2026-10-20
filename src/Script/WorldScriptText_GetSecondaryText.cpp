#include <globaldefs.h>
ARM
extern "C" unsigned char* WorldScriptArray_FindEntryByKey();
// Original: arm9/main @ 0x0208DA00; symbol: func_0208da00; size: 0x18.
 extern "C" unsigned int WorldScriptText_GetSecondaryText() { unsigned char* p=WorldScriptArray_FindEntryByKey(); return p ? *(unsigned int*)(p+8) : 0; }
