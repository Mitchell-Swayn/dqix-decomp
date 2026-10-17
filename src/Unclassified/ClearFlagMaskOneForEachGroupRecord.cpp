#include <globaldefs.h>
ARM
extern "C" unsigned char* FindNonnegativeKeyInCountedRecordArray(void*,int);extern "C" void ClearMaskedFlagsAtOffset2A(void*,int,unsigned);
// Original: arm9/main @ 0x02080BAC; symbol: func_02080bac; size: 0x58.
extern "C" void ClearFlagMaskOneForEachGroupRecord(unsigned char* p,int key){unsigned char* entry=FindNonnegativeKeyInCountedRecordArray(p+12,key);if(!entry)return;for(short i=0;i<entry[19];i++)ClearMaskedFlagsAtOffset2A(p+4,(*(short**)entry)[i],1);}
