#include <globaldefs.h>
extern "C" char* FindVariableStrideRecordByKey(unsigned,unsigned,unsigned,unsigned);
extern "C" void Object_SetIntAtOffsetC(char*);
// Original: arm9/main @ 0x020B01F0; symbol: func_020b01f0; size: 0x3C.
extern "C" int ResourceFile_FindAndRelocateTTLPChunk(unsigned a,char** out,unsigned c,unsigned d) {char* p=FindVariableStrideRecordByKey(a,0x504c5454,c,d);if(!p){*out=0;return 0;}Object_SetIntAtOffsetC(p+8);*out=p+8;return 1;}
