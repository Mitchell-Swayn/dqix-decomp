#include <globaldefs.h>
ARM
extern "C" void Object_SetUnsignedIntAtOffset44AndSetUnsignedIntAtOffset48AndSetUnsignedIntAtOffset4C(void*,unsigned int,unsigned int,unsigned int);
// Original: arm9/main @ 0x02040774; symbol: func_02040774; size: 0x40.
extern "C" void SetThreeValuesOnFirstAvailableRepresentation(unsigned char* p,unsigned int a,unsigned int b,unsigned int c) { unsigned int* q=*(unsigned int**)(p+0x14);if(q) { q[1]=a;q[2]=b;q[3]=c;return; }void* second=*(void**)(p+0x18);if(second) { Object_SetUnsignedIntAtOffset44AndSetUnsignedIntAtOffset48AndSetUnsignedIntAtOffset4C(second,a,b,c);return; }void* third=*(void**)(p+0x1c);if(!third)return;Object_SetUnsignedIntAtOffset44AndSetUnsignedIntAtOffset48AndSetUnsignedIntAtOffset4C(third,a,b,c); }
