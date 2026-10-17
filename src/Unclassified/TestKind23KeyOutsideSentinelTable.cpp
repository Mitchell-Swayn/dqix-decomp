// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x0209C0F4; symbol: func_0209c0f4; size: 0x4C.
extern "C" int TestKind23KeyOutsideSentinelTable(int key,int kind){if(kind!=23)return 1;if(key<0)return 1;signed char* p=data_020e8ebc;while(*p>-1){if(*p==key)return 0;++p;}return 1;}
