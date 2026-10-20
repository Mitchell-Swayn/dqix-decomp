#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0221B158; symbol: func_ov031_0221b158; size: 0x44.
// Counts the set bits across four bytes and returns the count as a byte.
extern "C" unsigned char CountSetBitsInFourBytes(const unsigned char* bytes){
 int count;int i=0;count=0;
 do{int bit=0;int value=bytes[i];
 do{int shifted=value>>bit;++bit;if(shifted&1)++count;}while(bit<8);
 ++i;}while(i<4);
 return count;
}
