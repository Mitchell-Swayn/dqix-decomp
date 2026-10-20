// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x02081EE4; symbol: func_02081ee4; size: 0x3C.
extern "C" void KeyRepeater_Initialize(char* p,char* q){*(char**)p=0;if(q){*(char**)p=q;*(short*)q=0;q[2]=0;}*(short*)(p+4)=0;p[6]=20;p[7]=10;p[8]=p[6];}
