// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x02042AF4; symbol: func_02042af4; size: 0x1C.
extern "C" void ClearIndexedPackedBit(int unused,unsigned char* p,int index){unsigned int bit=index&7;p[index>>3]&=~(1u<<bit);}
