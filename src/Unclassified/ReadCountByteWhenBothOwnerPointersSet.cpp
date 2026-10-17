// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
extern "C" unsigned int data_02109d8c[];extern "C" char data_02109da4[];extern "C" unsigned int* data_021118e0[];
// Original: arm9/main @ 0x0205D67C; symbol: func_0205d67c; size: 0x24.
extern "C" unsigned int ReadCountByteWhenBothOwnerPointersSet(char* p){if(!*(int*)(p+0x98))return 0;return *(int*)(p+0x9c)?(unsigned char)p[0xb4]:0;}
