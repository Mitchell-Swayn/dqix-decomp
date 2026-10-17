// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x020E1288; symbol: func_020e1288; size: 0x20.
extern "C" unsigned int Object_ReadHalfProductOfTwoNestedBytes(char* p){char* q=*(char**)(p+8);if(q)return ((unsigned char)q[10]*(unsigned char)q[11])>>1;return 0;}
