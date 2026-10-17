#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char* data_ov031_0224e53c;
// Original: arm9/ov031 @ 0x0220D8F4; symbol: func_ov031_0220d8f4; size: 0x90.
extern "C" unsigned short Util_FindNextEnabledBitModuloThirteen(int start){
 int i;
 unsigned flags=*(unsigned*)(data_ov031_0224e53c+0x2264);
 int value=start;
 for(i=0;i<13;i++,value++){
 if(flags&(1<<(value%13+1)))break;
 }
 return (start+i)%13+1;
}
