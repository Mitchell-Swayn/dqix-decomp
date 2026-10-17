// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x020535F4; symbol: func_020535f4; size: 0x10.
extern "C" void IncrementByteField184(unsigned char* p){++p[0x184];}
