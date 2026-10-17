// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x0204AF14; symbol: func_0204af14; size: 0x24.
extern "C" char* GetSixteenByteEntryBoundedByByte1DFromPointer10(char* p,unsigned int i){char* q=*(char**)(p+0x10);if(!q)return 0;if((unsigned char)p[0x1d]<=i)return 0;return q+i*16;}
