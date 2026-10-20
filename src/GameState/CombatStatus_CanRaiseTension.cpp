// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x020881C4; symbol: func_020881c4; size: 0x44.
extern "C" int CombatStatus_CanRaiseTension(char* p){unsigned int f=*(unsigned int*)(p+20);if(f&1)return 0;if(f&0x1000000)return 0;if(f&16)return 0;if(f&0x80000)return 0;return !(f&8);}
