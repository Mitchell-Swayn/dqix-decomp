// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x020D9FB4; symbol: func_020d9fb4; size: 0x14.
extern "C" void SetMaskedFlagsAtOffset8(char* p,unsigned int bit){*(unsigned short*)(p+8)|=1u<<bit;}
