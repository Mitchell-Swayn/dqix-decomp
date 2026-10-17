#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A0AF4; symbol: func_020a0af4; size: 0x48.
extern "C" int FindNonnegativeHalfwordKeyIndex(unsigned char* p,int key) { short* entries=*(short**)p;short count=*(short*)(p+8);if(key<0)return -1;for(short i=0;i<count;i++)if(key==entries[i])return i;return -1; }
