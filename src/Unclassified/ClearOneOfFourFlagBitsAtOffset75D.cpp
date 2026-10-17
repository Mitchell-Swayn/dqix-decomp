// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x02026394; symbol: func_02026394; size: 0x1C.
extern "C" void ClearOneOfFourFlagBitsAtOffset75D(unsigned char* p,unsigned int bit){if(bit<4)p[0x75d]&=~(1u<<bit);}
