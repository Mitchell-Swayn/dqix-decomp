// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x020A2CD8; symbol: func_020a2cd8; size: 0x18.
extern "C" void SetByteField245FlagBitOne(unsigned char* p,int v){unsigned int byte=p[0x245];if(v)byte|=2;else byte&=~2u;p[0x245]=byte;}
