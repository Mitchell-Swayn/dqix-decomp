#include <globaldefs.h>
ARM
extern "C" char* FindVariableStrideRecordByKey(unsigned,unsigned,unsigned,unsigned); extern "C" void RelocateWordOffsetAtField4AgainstBase(char*);
// Original: arm9/main @ 0x020B022C; symbol: func_020b022c; size: 0x3C.
 extern "C" int ParsePMCPResourceBlock(unsigned a,char** out,unsigned c,unsigned d){char* p=FindVariableStrideRecordByKey(a,0x50434d50,c,d); if(!p){*out=0;return 0;}RelocateWordOffsetAtField4AgainstBase(p+8);*out=p+8;return 1;}
