// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x0208977C; symbol: func_0208977c; size: 0x10.
extern "C" void InvalidateHalfwordPair2AAnd2C(char* p){*(short*)(p+0x2a)=-1;*(short*)(p+0x2c)=-1;}
