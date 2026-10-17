#include <globaldefs.h>
ARM
extern "C" unsigned char* ReadWordFieldAtOffset1C();extern "C" void Object_SetWordAtOffset1E20(void*,void*);extern "C" int Object_TestNestedOffset440StateEqualsTwo(void*);extern "C" void PointField1E20AtEmbedded914(void*);
// Original: arm9/main @ 0x0205CD94; symbol: func_0205cd94; size: 0x54.
extern "C" void UpdateContextPairForEmbeddedDisplay(unsigned char* p){unsigned char* ctx=ReadWordFieldAtOffset1C();Object_SetWordAtOffset1E20(ctx,p+180);if(!Object_TestNestedOffset440StateEqualsTwo(ctx+0x19e0)){(*(unsigned**)(ctx+0x1e20))[2]=2;(*(unsigned**)(ctx+0x1e20))[5]=4096;}PointField1E20AtEmbedded914(ctx);}
