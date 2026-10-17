// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x020D1468; symbol: func_020d1468; size: 0x48.
extern "C" void System_SaveBusControlBitsAndSetDefaultBusMode(int* p){volatile unsigned short* reg=(volatile unsigned short*)0x04000204;p[0]=(*reg&12)>>2;p[1]=(*reg&16)>>4;*reg=(*reg&~12)|12;*reg=*reg&~16;}
