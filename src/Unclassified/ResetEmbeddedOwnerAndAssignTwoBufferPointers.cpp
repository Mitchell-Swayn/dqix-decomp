#include <globaldefs.h>
ARM
extern "C" void Object_ClearOptionalOffset440RecordWord8(void*);
// Original: arm9/main @ 0x020430B0; symbol: func_020430b0; size: 0x60.
extern "C" void ResetEmbeddedOwnerAndAssignTwoBufferPointers(unsigned char* p){Object_ClearOptionalOffset440RecordWord8(p+0x19e0);*(void**)(p+0x1e20)=p+0x930;Object_ClearOptionalOffset440RecordWord8(p+0x19e0);*(void**)(p+0x1e20)=p+0x914;p[0x19b1]=0;p[0x19ae]=0;p[0x19af]=0;p[0x19bd]=0;*(int*)(p+0x1838)=-1;*(int*)(p+0x183c)=0;}
