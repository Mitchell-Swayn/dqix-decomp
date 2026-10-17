extern "C" short data_020e87c0[];
// Original: arm9/main @ 0x0206E3E8; symbol: func_0206e3e8; size: 0x3C.
extern "C" int FindKeyInThirtyTwoHalfwords(int unused,int key){short result=0;short* p=data_020e87c0;for(int i=0;i<32;++i,++p){if(*p==key){result=i;break;}}return result;}
