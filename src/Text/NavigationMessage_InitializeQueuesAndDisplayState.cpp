#pragma thumb off
#pragma optimization_level 2

extern "C" {void NavigationMessage_ClearEntry(void*);void* memset(void*,int,unsigned);}
struct PairFlags{unsigned char value:7,flag:1;};
// Original: arm9/main @ 0x020938F0; symbol: func_020938f0; size: 0x90.
extern "C" void NavigationMessage_InitializeQueuesAndDisplayState(unsigned char* object){for(int i=0;i<8;++i){NavigationMessage_ClearEntry(object+i*0x34);NavigationMessage_ClearEntry(object+0x1a0+i*0x34);}*(int*)(object+0x340)=-1;*(int*)(object+0x344)=0;memset(object+0x348,0,0x80);PairFlags* f=(PairFlags*)(object+0x3c8);f->value=0;f->flag=1;object[0x3c9]&=~1;object[0x3ca]=0;object[0x3cb]=0;object[0x3cc]=0;struct Nibble{unsigned char value:4,other:4;}; Nibble* n=(Nibble*)(object+0x3cd);object[0x3cd]=0;object[0x3cd]=(unsigned char)(object[0x3cd]|8);}
