// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x02088E04; symbol: func_02088e04; size: 0x44.
extern "C" int AreWordFlags80039Clear(char* p){unsigned int f=*(unsigned int*)(p+20);if(f&1)return 0;if(f&16)return 0;if(f&0x80000)return 0;if(f&8)return 0;return !(f&32);}
