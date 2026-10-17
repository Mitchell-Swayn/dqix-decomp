// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x020488CC; symbol: func_020488cc; size: 0x20.
extern "C" void SetEnabledByteAndClearCompanionByte(char* p,int v){p[0x180]=v!=0;if(v)p[0x17f]=0;}
