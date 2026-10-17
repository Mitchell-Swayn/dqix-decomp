#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *FindTwoHundredTwentyFourByteRecordByByteKey(unsigned char *,int);
// Original: arm9/main @ 0x02080C20; symbol: func_02080c20; size: 0x1C.
void ClearResolvedEntryByteC5Bit20(unsigned char *p,int i){unsigned char *q=FindTwoHundredTwentyFourByteRecordByByteKey(p,i);if(q)q[0xc5]&=~32;}
}
