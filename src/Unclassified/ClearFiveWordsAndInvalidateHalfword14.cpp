// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x0203C0CC; symbol: func_0203c0cc; size: 0x24.
extern "C" void ClearFiveWordsAndInvalidateHalfword14(char* p){*(int*)(p+4)=0;*(int*)p=0;*(int*)(p+8)=0;*(int*)(p+16)=0;*(int*)(p+12)=0;*(short*)(p+20)=-1;}
