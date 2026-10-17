// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x0205D5B8; symbol: func_0205d5b8; size: 0x18.
extern "C" void Object_SetBooleanMask20AtOffsetC5(unsigned char* p,int v){unsigned int byte=p[0xc5];if(v)byte|=32;else byte&=~32u;p[0xc5]=byte;}
