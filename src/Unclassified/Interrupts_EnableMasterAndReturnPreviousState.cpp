// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x020D6C9C; symbol: func_020d6c9c; size: 0x18.
extern "C" unsigned int Interrupts_EnableMasterAndReturnPreviousState(){volatile unsigned short* reg=(volatile unsigned short*)0x04000208;unsigned int old=*reg;*reg=1;return old;}
