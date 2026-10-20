#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02067F5C; symbol: func_02067f5c; size: 0x40.
extern "C" void Text_UppercaseBoundedASCIICharacters(signed char* p,int length) { if(!p)return;for(int i=0;i<length;i++,p++) { int c=*p;if(!c)return;if(c>=97 && c<=122)c-=32;*p=c; } }
