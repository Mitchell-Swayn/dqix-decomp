#include <globaldefs.h>
ARM
extern "C" unsigned char* FindNonnegativeKeyInEntryArray(void*,int);
// Original: arm9/main @ 0x0208077C; symbol: func_0208077c; size: 0x1C.
extern "C" void SetKeyedRecordHalfwordField28(unsigned char* p,int key,int value){unsigned char* q=FindNonnegativeKeyInEntryArray(p+4,key);if(q)*(short*)(q+40)=value;}
