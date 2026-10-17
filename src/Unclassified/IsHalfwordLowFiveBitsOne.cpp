// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x0204BDC0; symbol: func_0204bdc0; size: 0x18.
extern "C" int IsHalfwordLowFiveBitsOne(unsigned short* p){return (p[1]&31)==1;}
