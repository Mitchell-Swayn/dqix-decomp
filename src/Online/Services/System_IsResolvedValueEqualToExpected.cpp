#include <globaldefs.h>
ARM
extern "C" int Http_GetCompletedResponseBody(void*, unsigned int*);
// Original: arm9/ov031 @ 0x0223F740; symbol: func_ov031_0223f740; size: 0x2C.
extern "C" unsigned int System_IsResolvedValueEqualToExpected(void* object, unsigned int* record) { unsigned int temp; int value = Http_GetCompletedResponseBody(object, &temp); return value == *(unsigned int*)((char*)record + 0x14); }
