// Reviewed original ARM field widths and source behavior; float initialization is a real 1.0 constant.
extern "C" {int strcmp(const char*,const char*);void* memset(void*,int,unsigned);void func_02030b0c(void*);}
// Original: arm9/main @ 0x02094A24; symbol: func_02094a24; size: 0x8C.
extern "C" void InitializeOwnerWordsAndEightIndexSentinels(char* p){*(int*)p=0;*(int*)(p+4)=0;*(int*)(p+8)=0;*(int*)(p+12)=0;*(int*)(p+16)=0;for(int i=0;i<8;++i)*(int*)(p+i*4+20)=-1;*(int*)(p+60)=-1;*(int*)(p+64)=-1;*(int*)(p+56)=-1;*(int*)(p+52)=-1;memset(p+68,0,16);p[85]=0;p[84]=0;p[86]=1;p[87]=0;p[98]=0;p[97]=0;p[99]=0;p[100]=0;}
