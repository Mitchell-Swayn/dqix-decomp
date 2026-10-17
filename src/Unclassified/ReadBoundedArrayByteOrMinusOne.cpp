// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x0209C0A8; symbol: func_0209c0a8; size: 0x18.
extern "C" int ReadBoundedArrayByteOrMinusOne(unsigned short* p,int i){if(p[12]<=i)return -1;return p[i];}
