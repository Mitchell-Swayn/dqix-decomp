#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *FindTwoHundredTwentyFourByteRecordByByteKey(void *,int);
// Original: arm9/main @ 0x02080C3C; symbol: func_02080c3c; size: 0x2C.
bool IsKeyedRecordByteFlagBitFiveClear(void *p,int i){unsigned char *q=FindTwoHundredTwentyFourByteRecordByByteKey(p,i);if(q)return !(q[0xc5]&32);return false;}
}
