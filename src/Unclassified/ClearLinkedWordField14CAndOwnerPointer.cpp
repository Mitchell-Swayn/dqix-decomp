// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x020BEC80; symbol: func_020bec80; size: 0x18.
extern "C" void ClearLinkedWordField14CAndOwnerPointer(char** p){char* q=*p;if(q){*(int*)(q+0x14c)=0;*p=0;}}
