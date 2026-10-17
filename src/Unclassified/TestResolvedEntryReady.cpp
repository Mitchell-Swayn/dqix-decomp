#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void *FindTwoHundredTwentyFourByteRecordByByteKey(void *,int);int AreBothWordFieldsD4And9CNonzero(void *);
// Original: arm9/main @ 0x020811E8; symbol: func_020811e8; size: 0x2C.
bool TestResolvedEntryReady(void *p,int i){void *q=FindTwoHundredTwentyFourByteRecordByByteKey(p,i);if(q)return AreBothWordFieldsD4And9CNonzero(q)!=0;return false;}
}
