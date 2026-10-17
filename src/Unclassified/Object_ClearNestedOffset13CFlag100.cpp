// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x02048C50; symbol: func_02048c50; size: 0x18.
extern "C" void Object_ClearNestedOffset13CFlag100(char* p){char* q=*(char**)(p+0x13c);if(q)*(unsigned int*)(q+32)&=~256u;}
