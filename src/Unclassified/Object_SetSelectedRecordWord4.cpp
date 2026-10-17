#include <globaldefs.h>
ARM
extern "C" unsigned* FindThirtyTwoByteRecordByHalfwordKey(void*,int);
// Original: arm9/main @ 0x0209BE28; symbol: func_0209be28; size: 0x1C.
extern "C" void Object_SetSelectedRecordWord4(void* p,int key,unsigned* value){unsigned* q=FindThirtyTwoByteRecordByHalfwordKey(p,key);if(q)q[1]=*value;}
