#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020278A4; symbol: func_020278a4; size: 0x40.
extern "C" int WorldMap_FindBackgroundResourceIndex(unsigned char* p,unsigned key){for(int i=0;i<*(int*)(p+36);++i){unsigned char* records=*(unsigned char**)(p+32);if(*(unsigned*)(records+i*36)==key)return i;}return -1;}
