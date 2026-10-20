#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov001 @ 0x0215E374; symbol: func_ov001_0215e374; size: 0x24.
extern "C" int Grotto_SetNestedSecondWordFromGlobalByte(void* p) { unsigned char value = *((unsigned char*)((char*)TextContext_GetSharedInstance() + 0x19bd)); Script_WriteIntegerReferenceOutput(p, value); return 1; }
