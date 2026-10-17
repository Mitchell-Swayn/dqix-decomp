// Original instruction control flow and relocations reviewed.
extern "C" char* data_02110370[];extern "C" unsigned short data_02108d70[];extern "C" unsigned int data_0210f3c0[];struct Flag{unsigned char enabled:1;unsigned char rest:7;};
// Original: arm9/main @ 0x02088C54; symbol: func_02088c54; size: 0x20.
extern "C" int AreWordField14FlagBitsZeroAndSeventeenClear_Main02088C54(char* p){unsigned int f=*(unsigned int*)(p+20);if(f&1)return 0;return !(f&0x20000);}
