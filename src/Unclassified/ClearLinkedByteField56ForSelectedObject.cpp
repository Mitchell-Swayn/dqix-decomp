#include <globaldefs.h>
ARM
extern "C" bool Object_TestNestedOffset138Word14Bit0(void*);
// Original: arm9/main @ 0x02049EFC; symbol: func_02049efc; size: 0x2C.
 extern "C" void ClearLinkedByteField56ForSelectedObject(unsigned char* p) { if (!*(void**)(p+0x13c))return; if (Object_TestNestedOffset138Word14Bit0(p)) (*(unsigned char**)(p+0x13c))[0x56]=0; }
