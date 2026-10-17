#include <globaldefs.h>
ARM
extern "C" char* FindVariableStrideRecordByKey(void*,unsigned);extern "C" void RelocateWordOffsetAtField14AgainstBase(void*);
// Original: arm9/main @ 0x020B01A4; symbol: func_020b01a4; size: 0x3C.
extern "C" int ParseRAHCResourceBlock(void* file,void** out){char* p=FindVariableStrideRecordByKey(file,0x43484152);if(!p){*out=0;return 0;}RelocateWordOffsetAtField14AgainstBase(p+8);*out=p+8;return 1;}
