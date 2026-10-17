// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x02045824; symbol: func_02045824; size: 0x40.
extern "C" void WriteSelectedOrAllFourField186CValues(char* p,int value,int i){if(i==-1){for(int n=0;n<4;++n)*(int*)(p+n*4+0x186c)=value;}else *(int*)(p+i*4+0x186c)=value;}
