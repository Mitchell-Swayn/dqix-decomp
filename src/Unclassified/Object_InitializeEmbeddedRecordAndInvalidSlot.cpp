#include <globaldefs.h>
ARM
extern "C" void Object_ClearFortyByteRecord(void*);
// Original: arm9/main @ 0x02040258; symbol: func_02040258; size: 0x24.
extern "C" void Object_InitializeEmbeddedRecordAndInvalidSlot(unsigned char* p){p[0]=0;Object_ClearFortyByteRecord(p+16);*(int*)(p+56)=-1;}
