// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x020979C0; symbol: func_020979c0; size: 0x34.
extern "C" void Object_InitializeThirtyOneByteRecordWithParameter(char* p,int v){*(int*)p=0;*(int*)(p+4)=0;*(int*)(p+8)=0;*(int*)(p+12)=0;*(int*)(p+16)=0;*(int*)(p+20)=0;*(int*)(p+24)=-1;p[28]=0;p[29]=v;p[30]=0;}
