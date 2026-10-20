#include <globaldefs.h>
ARM
extern "C" int String_CompareSignedBytes(char* a, char* b);
// Original: arm9/ov031 @ 0x02241534; symbol: func_ov031_02241534; size: 0xC.
extern "C" int Util_CompareStringsViaSignedCharacterRoutine(char* a, char* b) { return String_CompareSignedBytes(a, b); }
