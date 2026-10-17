#include <globaldefs.h>
ARM
extern "C" unsigned char* ReadWordFieldAtOffset1C(void*);extern "C" void Object_SetWordAtOffset1E20(void*,void*);extern "C" int Object_TestNestedOffset440StateEqualsTwo(void*);extern "C" void PointField1E20AtEmbedded914(void*);
// Original: arm9/main @ 0x0205CDE8; symbol: func_0205cde8; size: 0x40.
extern "C" bool SaveContextReadFadePredicateAndRestoreContext(unsigned char* p){unsigned char* q=ReadWordFieldAtOffset1C(p);Object_SetWordAtOffset1E20(q,p+180);bool result=Object_TestNestedOffset440StateEqualsTwo(q+0x19e0)!=0;PointField1E20AtEmbedded914(q);return result;}
