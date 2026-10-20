#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A83B0; symbol: func_020a83b0; size: 0x4C.
extern "C" unsigned char* ZoomDestination_FindByDisplayIndex(unsigned char* p,int key) { if(key<0)return 0;for(int i=0;i<*(unsigned short*)(p+6);++i) { unsigned char* entry=*(unsigned char**)p+i*44;if((unsigned int)key==entry[1])return entry; }return 0; }
