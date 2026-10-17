// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x0204ACB0; symbol: func_0204acb0; size: 0x20.
extern "C" void ClearHalfwordPairBytePairAndWordPair(char* p){*(short*)p=0;*(short*)(p+2)=0;p[4]=0;p[5]=0;*(int*)(p+8)=0;*(int*)(p+12)=0;}
