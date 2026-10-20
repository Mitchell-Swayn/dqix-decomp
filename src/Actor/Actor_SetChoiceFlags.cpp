#include <globaldefs.h>
ARM
extern "C" unsigned* Actor_FindChoiceById(void*,int);
// Original: arm9/main @ 0x0209BE28; symbol: func_0209be28; size: 0x1C.
extern "C" void Actor_SetChoiceFlags(void* p,int key,unsigned* value){unsigned* q=Actor_FindChoiceById(p,key);if(q)q[1]=*value;}
