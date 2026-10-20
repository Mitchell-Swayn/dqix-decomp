// Original: arm9/main @ 0x020D3018; symbol: func_020d3018; size: 0x2C.
extern "C" int String_CompareSignedBytes(char* a,char* b){char x,y;for(; (y=*b,x=*a,x==y && x!=0);++a,++b){}return x-y;}
