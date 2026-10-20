// Original: arm9/main @ 0x020465D8; symbol: func_020465d8; size: 0x18.
extern "C" void TextContext_SetNumericArgumentAlignment(char* p,int i,int v){if(i<0)return;if(i<16)*(char*)(p+i+0x8f1)=v;}
