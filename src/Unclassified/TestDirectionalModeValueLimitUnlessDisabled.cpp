// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x02087D24; symbol: func_02087d24; size: 0x54.
extern "C" int TestDirectionalModeValueLimitUnlessDisabled(char* p,int dir){if(*(unsigned int*)(p+20)&1)return 0;if(dir==0){int v=((Mode*)(p+0x58))->value;if(v<2)return 1;}else{int v=((Mode*)(p+0x58))->value;if(v>-2)return 1;}return 0;}
