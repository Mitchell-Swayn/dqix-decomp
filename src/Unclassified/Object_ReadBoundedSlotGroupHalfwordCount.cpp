#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0207C620; symbol: func_0207c620; size: 0x18.
int Object_ReadBoundedSlotGroupHalfwordCount(short *p,unsigned int i){int result;if(i>7)result=-1;else result=*(short *)((char *)(p+i)+0xc10);return result;}
}
