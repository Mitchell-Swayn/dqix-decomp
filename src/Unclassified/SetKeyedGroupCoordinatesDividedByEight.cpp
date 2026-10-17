#include <globaldefs.h>
ARM
extern "C" unsigned char* FindNonnegativeKeyInCountedRecordArray(void*,int);
// Original: arm9/main @ 0x020807FC; symbol: func_020807fc; size: 0x2C.
extern "C" void SetKeyedGroupCoordinatesDividedByEight(unsigned char* p,int key,int x,int y){unsigned char* q=FindNonnegativeKeyInCountedRecordArray(p+12,key);if(q){*(short*)(q+10)=x>>3;*(short*)(q+12)=y>>3;}}
