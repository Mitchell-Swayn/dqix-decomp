// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x02053DA0; symbol: func_02053da0; size: 0x20.
extern "C" void Object_SetAndClearNestedOffset19CRecord(char* p,char* q){*(char**)(p+0x19c)=q;*(short*)q=0;q[2]=0;q[3]=0;q[4]=0;*(int*)(q+8)=0;}
