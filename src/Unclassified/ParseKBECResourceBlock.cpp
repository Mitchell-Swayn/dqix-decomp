#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" char* FindVariableStrideRecordByKey(unsigned,unsigned,unsigned,unsigned);
extern "C" void ResourceRecord_RelocateNestedEntryOffsets(char*);
// Original: arm9/main @ 0x020B00A4; symbol: func_020b00a4; size: 0x3C.
extern "C" int ParseKBECResourceBlock(unsigned a,char** out,unsigned c,unsigned d){
    char* p=FindVariableStrideRecordByKey(a,0x4345424b,c,d);
    if(!p){*out=0;return 0;}
    ResourceRecord_RelocateNestedEntryOffsets(p+8);
    *out=p+8;
    return 1;
}
