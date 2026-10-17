#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204C610; symbol: func_0204c610; size: 0x44.
extern "C" void ReadFourBoundedHalfwordArrays(unsigned char* p,int i,short* a,short* b,short* c,short* d) { if(i<0)return;if(i>=18)return;unsigned char* entry=p+i*2;*a=*(short*)(entry+12);*b=*(short*)(entry+48);*c=*(short*)(entry+84);*d=*(short*)(entry+120); }
