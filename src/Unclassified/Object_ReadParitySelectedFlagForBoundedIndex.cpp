#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0206E260; symbol: func_0206e260; size: 0x40.
extern "C" unsigned int Object_ReadParitySelectedFlagForBoundedIndex(unsigned char* p,int index) { if(index>=204 || index<0)return 0; unsigned int mask=index%2 ? 64:4; return mask & (p+index/2)[0x2cc]; }
