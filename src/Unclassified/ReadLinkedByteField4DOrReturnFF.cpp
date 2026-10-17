// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x0204948C; symbol: func_0204948c; size: 0x14.
extern "C" unsigned int ReadLinkedByteField4DOrReturnFF(char* p){char* q=*(char**)(p+0x13c);if(q)return (unsigned char)q[0x4d];return 255;}
