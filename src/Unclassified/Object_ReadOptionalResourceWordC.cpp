extern "C" char* ReadSignedWordAtOffset4(char*);
// Original: arm9/main @ 0x020550D8; symbol: func_020550d8; size: 0x18.
extern "C" int Object_ReadOptionalResourceWordC(char* p){char* q=ReadSignedWordAtOffset4(p);int v;if(q==0)v=0;else v=*(int*)(q+12);return v;}
