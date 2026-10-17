#include <globaldefs.h>
ARM
extern "C" unsigned char* FindNonnegativeKeyInCountedRecordArray(void*,int);extern "C" void ClearMaskedFlagsAtOffset2A(void*,int,unsigned);
// Original: arm9/main @ 0x0208065C; symbol: func_0208065c; size: 0x54.
extern "C" void SetFlagTwoForEachListedId(unsigned char* p,int key){unsigned char* entry=FindNonnegativeKeyInCountedRecordArray(p+12,key);if(!entry)return;for(unsigned char i=0;i<entry[19];i++)ClearMaskedFlagsAtOffset2A(p+4,(*(short**)entry)[i],2);}
