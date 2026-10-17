// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x02042C3C; symbol: func_02042c3c; size: 0x18.
extern "C" void Object_WriteHalfwordPairInOptionalOffset440Record(char* p,int a,int b){char* q=*(char**)(p+0x440);if(q){*(short*)(q+4)=a;q=*(char**)(p+0x440);*(short*)(q+6)=b;}}
