#include <globaldefs.h>
ARM
extern "C" unsigned AlignAddressToWord(unsigned);
extern "C" unsigned Math_SumAlignedHeaderFields(void*);
// Original: arm9/ov031 @ 0x0220547C; symbol: func_ov031_0220547c; size: 0x80.
extern "C" unsigned Memory_ComputeAlignedRecordStorageSize(unsigned char* p){
 unsigned size=128;
 if(*(unsigned short*)(p+2)){
 size+=0x114;
 size+=AlignAddressToWord(*(unsigned short*)(p+2));
 size+=AlignAddressToWord(*(unsigned short*)(p+8));
 size+=Math_SumAlignedHeaderFields(p+0x10);
 }
 if(*(unsigned short*)(p+6)){
 size+=0x110;
 size+=AlignAddressToWord(*(unsigned short*)(p+6));
 size+=AlignAddressToWord(*(unsigned short*)(p+10));
 size+=AlignAddressToWord(*(unsigned short*)(p+12));
 size+=Math_SumAlignedHeaderFields(p+0x14);
 }
 return size;
}
