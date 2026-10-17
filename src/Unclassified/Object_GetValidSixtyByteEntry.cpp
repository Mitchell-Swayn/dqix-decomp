#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02040468; symbol: func_02040468; size: 0x44.
extern "C" unsigned char* Object_GetValidSixtyByteEntry(unsigned int* p,unsigned int i) { unsigned char* base=(unsigned char*)p[2];if(!base)return 0;if((int)i<0 || p[0]<=i)return 0;unsigned char* entry=base+i*60;if(*(int*)(entry+0x38)<0)entry=0;return entry; }
